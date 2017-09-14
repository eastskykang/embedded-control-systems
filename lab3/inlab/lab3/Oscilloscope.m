function varargout = Oscilloscope(varargin)
% OSCILLOSCOPE M-file for Oscilloscope.fig
%      OSCILLOSCOPE, by itself, creates a new OSCILLOSCOPE or raises the existing
%      singleton*.
%
%      H = OSCILLOSCOPE returns the handle to a new OSCILLOSCOPE or the handle to
%      the existing singleton*.
%
%      OSCILLOSCOPE('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in OSCILLOSCOPE.M with the given input
%      arguments.
%
%      OSCILLOSCOPE('Property','Value',...) creates a new OSCILLOSCOPE or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Oscilloscope_OpeningFunction gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Oscilloscope_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Oscilloscope

% Last Modified by GUIDE v2.5 09-Feb-2011 13:27:10

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Oscilloscope_OpeningFcn, ...
                   'gui_OutputFcn',  @Oscilloscope_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
               
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if(isempty(varargin)==0)
if strcmp(varargin(1),'pushbutton3_Callback')  %if something other than 'start' is called it will interrupt start
    gui_State.stop = 1;
else
    gui_State.stop = 0;
end
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Oscilloscope is made visible.
function Oscilloscope_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Oscilloscope (see VARARGIN)

% Choose default command line output for Oscilloscope
handles.output = hObject;


set(handles.pushbutton3,'Visible','on');
set(handles.text1,'Visible','off');
set(handles.pushbutton4,'Visible','off');
set(handles.text2,'Visible','on');
guidata(hObject, handles);

% Update handles structure
guidata(hObject, handles);
colordef black;


    
%Get all the COM Ports
serialInfo = instrhwinfo('serial');
%if you do not have the instrument toolbox, just use a similar instruction
%as:
%  serialInfo.AvailableSerialPorts  =  {'COM3'};%instrhwinfo('serial'); 
handles.COMPORTS    = serialInfo.AvailableSerialPorts;
NUM_COM=size(handles.COMPORTS(:),1);
if(NUM_COM<1)
    msgbox('No COM Port available.');
    error('');
end

% Update the popupmenu2
set(handles.popupmenu2,'String',handles.COMPORTS)

guidata(hObject,handles)


% UIWAIT makes Oscilloscope wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Oscilloscope_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)  %start button
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

colordef black;
%set(handles.axes2,'color','white');
%set(handles.axes5,'color','white');
%set(handles.axes6,'color','white');
colordef black;
axes(handles.axes2);
axes(handles.axes5);
axes(handles.axes6);
set(handles.pushbutton3,'Visible','off');
set(handles.text1,'Visible','on');
set(handles.pushbutton4,'Visible','on');
set(handles.text2,'Visible','off');
guidata(hObject, handles);

% buffer size below corresponds to the buffer size implemented in lab3o.c
% therefore, the number is not to be edited!
buffer_size = 1024;  %sets buffer size between code and serial port
Ts=1/50; %Sampling Time [ms] (50kHz)

%Get COM-Port from list
val_list=get(handles.popupmenu2,'Value');

COM = handles.COMPORTS(val_list);
disp('***** opening COM *******');
set(handles.popupmenu2,'Enable','off');

handles.stop = 0;
guidata(hObject,handles);


try
    set(handles.figure1,'Pointer','watch');
    drawnow;

    s1 = serial(COM, 'BaudRate', 115200, 'InputBufferSize',buffer_size,'Timeout',1);
    try
        fopen(s1);
    catch
        msgbox('Could not open the COM port, make sure that it is not open in another application or try another port.');
        set(handles.figure1,'Pointer','arrow');
        return;
    end

    set(handles.figure1,'Pointer','arrow');  

    if( strcmpi(s1.status, 'closed') ) %opens COM port 4
       disp('s1.Status = Closed')
    else
       disp('s1.Status = Open')
    end
    
    while(1)  %beginning of main loop
%     the DATA field includes 512 samples with 14 bit resolution each. A sample
%     is encoded in two characters. The allowed characters exclude the block start character
%     Character    | 1                    | 0                    |
%     Bit          | 7 | 6 .. 0           | 7 | 6 .. 0           | Bit 7 is the most significant bit
%     Value        | 0 | ( sample / 128 ) | 0 | ( sample % 128 ) |
%     so the first byte includes the 7 most significant bits, the second the 7 least significant bits of the data sample
% 
%     MPC                        MATLAB
%     |                           |                               < - - - - - - - - - -+
%     | ----+                     |                                        LOOP        :
%     |     | capture             |                                                    :
%     | < - +                     |                                                    :
%     |                           |                                                    :
%     | <----------'S'----------- |                                                    :
%     |                           |                                                    :
%     |                           | -----+                                             :
%     # --------BLOCK_START-----> |      | wait blockstart                             :
%     #                           | <----+                                             :
%     # send                      |                                                    :
%     #                           | -----+                                             :
%     # ------ DATA (1024 Bytes)  |      |                                             :
%     #       ------              |      | fread with timeout set to 3 seconds         :
%     #             ------        |      |                                             :
%     #                   ------> |      |                                             :
%     | ----+                     | <----+                                             :
%     |     | trigger             |                                                    :
%     | <---+                     | -----+                                             :
%     |                           |      | display                                     :
%     |                           | <----+                                             :
%     |                           |                               < - - - - - - - - - -+
        
%     Wait till the oscilloscope display is ready to receive the data 
       
        % check if the stop button has been hit
        handles = guidata(hObject);
        if ( handles.stop )
            error('stop');
        end
        
        % we start by flushing the receive buffer
        while(s1.BytesAvailable)
          fread(s1, s1.BytesAvailable);
        end

        % now wait for block start character, repeat to send the 'S'
        % until we receive it
        BLOCK_START = uint8(128);
        block_start_received = 0;
        fprintf(s1,'S'); % send an S character to the MPC board via the serial link 
        while( block_start_received == 0 ) 
            
            % check if the stop button has been hit
            handles = guidata(hObject);
            if ( handles.stop )
                error('stop');
            end
            
            % try to read the block start
            [c,count] = fread(s1,1,'uchar');
            
            if (count > 0 )
                block_start_received = ( uint8(c(1)) == BLOCK_START );
            else
                fprintf(s1,'S'); % send an S character to the MPC board via the serial link 
                disp('waiting for buffer to fill...');
                pause(1)
            end
        end
        
        % when we come here, we have received the block start
        % now get the 1024 bytes of data 
        
        % because s1 is a serial device, a timeout occurs if not the full
        % amount of data can be read. The function only returns after
        % reading the requested number of bytes has been received or until
        % timeout
        [ serial_data, count] = fread( s1, buffer_size, 'uchar');
        % check if we got all data bytes
        if buffer_size ~= count
            % we did not get the full block, throw away the full block,
            continue
        end

        % now transport decode the buffer
        corrected = zeros(1,buffer_size/2);
        for i= 0 : 1 : (buffer_size/2-1)
            %                  1st byte most significant 7 bits
            %                  2nd byte least significant 7 bits
            corrected(i+1) =   double(  serial_data( 2*i + 1 ) ) * 128 ...
                             + double(  serial_data( 2*i + 2 ) );
        end

        %3277 is the scaler to calibrate the conversin value 16384 to 5 volts
        real_time_corrected = corrected./3277; % converts bits to actual Volts
        t = linspace(0, floor(buffer_size/2)*Ts, floor(buffer_size/2)); %time scale for oscilloscope


        %filter a little bit of the DC value, makes the ac signal easier to see
%         frequency_corrected = real_time_corrected - 1.0; %0.5 gets rid of DC offset for FFT

        colordef black;

        %subplot(3,1,1)
        axes(handles.axes2)
        plot(corrected)
        axis([0 500 2000 14000])
        title('Raw Serial Data')
        ylabel('ADC value [bit]')
        xlabel('Sample [#]')
        grid


        %subplot(3,1,2)
        axes(handles.axes5)
        plot(t,real_time_corrected,'g')
        title('Serial Port (COM1) Calibrated Data')
        axis([0 10.24 0 5])
        ylabel('Voltage [V]')
        xlabel('Time [ms]')
        grid

        if (~any(isnan(real_time_corrected)))
            % complex spectrum (csp)
            csp=fft(real_time_corrected); 
            N = length(real_time_corrected);
            amplitude = abs(csp(1:N/2))*2/N;
            amplitude(1) = amplitude(1)/2;
            frequency = ((1:N/2)-1)*(1/Ts)/N;

            %subplot(3,1,3)
            axes(handles.axes6)
            plot(frequency,amplitude,'r');
            title('Frequency Content of Serial Data')
%             axis 'auto x'
            set(gca,'xtick',[0:2:30])
            line([25,25],[0, 2],'LineWidth',3)
            text(25,1.8,' \leftarrow Nyquist Frequency','Color','y','FontSize',12);
            axis([0 30 0 2])
%             axis 'auto y'
            ylabel('Power')
            xlabel('Frequency [kHz]')
            grid on
        end
    end
catch e
    set(handles.figure1,'Pointer','arrow');  
    if exist('s1','var')
        fclose(s1);
    end
    if ischar(e)
        if strcmp(e,'stop') == 0
            rethrow( e );
        end
    end
end


% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)  %stop button
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

set(handles.pushbutton3,'Visible','on');
set(handles.text1,'Visible','off');
set(handles.pushbutton4,'Visible','off');
set(handles.text2,'Visible','on');
set(handles.popupmenu2,'Enable','on');
handles.stop = 1;
guidata(hObject, handles);





% --- Executes during object deletion, before destroying properties.
function pushbutton3_DeleteFcn(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)




% --------------------------------------------------------------------
function File_Callback(hObject, eventdata, handles)
% hObject    handle to File (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)




% --- Executes on selection change in popupmenu2.
function popupmenu2_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu2 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu2


