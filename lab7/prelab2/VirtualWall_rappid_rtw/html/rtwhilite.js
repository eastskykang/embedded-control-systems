// Copyright 2007 The MathWorks, Inc.


function RTW_Hash(aHash) {
    if (aHash == null) {
        this.fHash = "";
    } else {
        this.fHash = aHash;
    };
    
    this.getHash = function() {
        return this.fHash;
    }

    this.setHash = function(aHash) {
        this.fHash = aHash;
    }
}

RTW_Hash.instance = null;

function RTW_TraceInfo(aFileLinks, aPrevButton, aNextButton, aPanel) {
  this.fFileLinks = aFileLinks;
  this.fLines = new Array();
  this.fNumLines = new Array();
  this.fFileIdxCache = new Array();
  this.fPrevButton = aPrevButton;
  this.fNextButton = aNextButton;
  this.fPanel = aPanel;
  this.fDisablePanel = false;
  this.fCurrFileIdx = 0;
  this.fCurrLineIdx = 0;
  this.fCurrCodeNode = null;
  this.getHtmlFileName = function(aIndex) {
    if (aIndex < this.fFileLinks.length) {
      var href = this.fFileLinks[aIndex].href;
      return href.substring(href.lastIndexOf('/')+1);
    }
  }
  this.getSrcFileName = function(aIndex) {
    var name = this.getHtmlFileName(aIndex);
    if (name)
      name = RTW_TraceInfo.toSrcFileName(name);
    return name;
  }
  this.getNumFileLinks = function() {
    return this.fFileLinks.length;
  }
  this.setFileLinkColor = function(aIndex, aColor) {
    var link = this.fFileLinks[aIndex];
    if (link && link.parentNode && link.parentNode.style)
      link.parentNode.style.backgroundColor = aColor;
  }
  this.highlightFileLink = function(aIndex, aColor) {
    for (var i = 0; i < this.fFileLinks.length; ++i) {
      this.setFileLinkColor(i, i == aIndex ? aColor : "");
    }
  }
  this.highlightCurrFileLink = function(aColor) {
    this.highlightFileLink(this.fCurrFileIdx);
  }
  this.highlightLines = function(aCodeNode,aColor) {
    this.fCurrCodeNode = aCodeNode;
    var lines = this.fLines[this.getHtmlFileName(this.fCurrFileIdx)];
    if (lines && aCodeNode) {
      for (var i = 0; i < lines.length; ++i) {
        var lineObj = aCodeNode.childNodes[lines[i]-1];
        if (lineObj)
          lineObj.style.backgroundColor=aColor;
      }
    }
  }
  this.getFileIdx = function(aFile) {
    if (this.fFileIdxCache[aFile] != null)
      return this.fFileIdxCache[aFile];
    for (var i = 0; i < this.fFileLinks.length; ++i) {
      if (this.getHtmlFileName(i) == aFile) {
        this.fFileIdxCache[aFile] = i;
        return i;
      }
    }
    return null;
  }
  this.getCurrFileIdx = function() { return this.fCurrFileIdx; }
  this.setNumHighlightedLines = function(aFileIdx, aNumLines) {
    this.fNumLines[aFileIdx] = aNumLines;
    var parent = this.fFileLinks[aFileIdx].parentNode;
    if (parent && parent.childNodes && parent.childNodes.length > 1 &&
        parent.lastChild.innerHTML != undefined) {
      if (aNumLines > 0)
        parent.lastChild.innerHTML = "&nbsp;("+aNumLines+")";
      else
        parent.lastChild.innerHTML = " ";
    }
  }
  this.getNumLines = function(aFileIdx) {
    return this.fNumLines[aFileIdx] != null ? this.fNumLines[aFileIdx] : 0;
  }
  this.getNumLinesAll = function() {
      var sum = 0;
      var len = this.fNumLines.length;
      for (var i = 0; i < len; ++i) {
          sum += this.getNumLines(i);
      }
      return sum;
  }
  this.removeHighlighting = function() {
    for (var i = 0; i < this.fFileLinks.length; ++i) {
      this.setFileLinkColor(i, "");
      this.setNumHighlightedLines(i, 0);
    }
    this.highlightLines(this.fCurrCodeNode,"");
    this.fCurrCodeObj = null;
    this.fLines = new Array();
    this.fNumLines = new Array();
    this.fFileIdxCache = new Array();
    if (this.fPrevButton) { this.fPrevButton.disabled = true; }
    if (this.fNextButton) { this.fNextButton.disabled = true; }
    if (this.fPanel) { this.fPanel.style.display = "none"; }
    this.fCurrFileIdx = 0;
    this.fCurrLineIdx = 0;
  }
  this.setCurrent = function(aFileIdx, aLineIdx) {
    this.fCurrFileIdx = aFileIdx;
    var numLines = this.getNumLines(aFileIdx);
    if (!numLines || aLineIdx >= numLines)
      this.fCurrLineIdx = -1;
    else
      this.fCurrLineIdx = aLineIdx;
    var allNumLines = this.getNumLinesAll();
    if (this.fPrevButton) {
      this.fPrevButton.disabled = (allNumLines <= 1 || !this.hasPrev());
    }
    if (this.fNextButton) {
      this.fNextButton.disabled = (allNumLines <= 1 || !this.hasNext());
    }
    if (this.fPanel && !this.fDisablePanel) {
      this.fPanel.style.display = 'block';
    }
  }
  this.setDisablePanel = function(aDisable) {
    this.fDisablePanel = aDisable;
  }
  this.getPrevFileIdx = function() {
    if (this.fCurrLineIdx > 0)
      return this.fCurrFileIdx;
    for (var i = this.fCurrFileIdx - 1; i >= 0; --i)
      if (this.fNumLines[i] > 0)
        return i;
    return null;
  }
  this.hasPrev = function() {
    return this.getPrevFileIdx() != null;
  }
  this.goPrev = function() {
    var fileIdx = this.getPrevFileIdx();
    if (fileIdx == null)
      return;
    if (fileIdx == this.fCurrFileIdx)
      --this.fCurrLineIdx;
    else {
      this.fCurrFileIdx = fileIdx;
      this.fCurrLineIdx = this.getNumLines(fileIdx) - 1;
    }
    if (this.fPrevButton)
      this.fPrevButton.disabled = !this.hasPrev();
    if (this.fNextButton)
      this.fNextButton.disabled = !this.hasNext();
  }
  this.getNextFileIdx = function() {
    if (this.fCurrLineIdx < this.getNumLines(this.fCurrFileIdx) - 1 && this.getNumLines(this.fCurrFileIdx) > 0)
      return this.fCurrFileIdx;
    for (var i = this.fCurrFileIdx + 1; i < this.getNumFileLinks(); ++i)
      if (this.fNumLines[i] > 0)
        return i;
    return null;
  }
  this.hasNext = function() {
    return this.getNextFileIdx() != null;
  }
  this.goNext = function() {
    var fileIdx = this.getNextFileIdx();
    if (fileIdx == null)
      return;
    if (fileIdx == this.fCurrFileIdx)
      ++this.fCurrLineIdx;
    else {
      this.fCurrFileIdx = fileIdx;
      this.fCurrLineIdx = 0;
    }
    if (this.fNextButton)
      this.fNextButton.disabled = !this.hasNext();
    if (this.fPrevButton)
      this.fPrevButton.disabled = !this.hasPrev();
  }
  this.setLines = function(aFile, aLines) {
    this.fLines[aFile] = aLines;
    var index = this.getFileIdx(aFile);
    if (index != null)
      this.setNumHighlightedLines(index,aLines.length);
  }
  this.getLines = function(aFile) {
    return this.fLines[aFile];
  }
  this.getHRef = function(aFileIdx, aLineIdx, offset) {
    if (offset == undefined)
      offset = 10;
    var file = this.getHtmlFileName(aFileIdx);
    var lines = this.fLines[file];
    if (lines) {
      var line = lines[aLineIdx];
      if (offset > 0)
        line = (line > offset ? line - offset : 1);
      file = file+"#"+line;
    }
    return file;
  }
  this.getCurrentHRef = function(offset) {
    return this.getHRef(this.fCurrFileIdx, this.fCurrLineIdx,offset);
  }
  this.setInitLocation = function(aFile, aLine) {
    var fileIdx = this.getFileIdx(aFile);
    var lineIdx = null;
    if (fileIdx != null) {
      var lines = this.getLines(aFile);
      for (var i = 0; i < lines.length; ++i) {
        if (lines[i] == aLine) {
          lineIdx = i;
          break;
        } 
      }
    }
    if (fileIdx == null || lineIdx == null)
      this.setCurrent(0,-1);
    else
      this.setCurrent(fileIdx,lineIdx);
  }
}


RTW_TraceInfo.getFileLinks = function(docObj) {
  var links;
  if (docObj && docObj.getElementsByName)
    links = docObj.getElementsByName("rtwIdGenFileLinks");
  return links ? links : new Array();
}

RTW_TraceInfo.toSrcFileName = function(aHtmlFileName) {
  aHtmlFileName = aHtmlFileName.replace(/_c.html$/,".c");
  aHtmlFileName = aHtmlFileName.replace(/_h.html$/,".h");
  aHtmlFileName = aHtmlFileName.replace(/_cpp.html$/,".cpp");
  aHtmlFileName = aHtmlFileName.replace(/_hpp.html$/,".hpp");
  aHtmlFileName = aHtmlFileName.replace(/_cc.html$/,".hpp");
  return aHtmlFileName;
}

RTW_TraceInfo.instance = null;

RTW_TraceArgs = function(aLocation) {
  this.fColor = null;
  this.fFontSize = null;
  this.fInitFile = null;
  this.fInitLine = null;
  this.fFiles = new Array();
  this.fLines = new Array();
  this.fMessage = null;
  this.fBlock = null;

  if (aLocation.search || aLocation.hash) {
    var query = null;
    if (aLocation.search)
      query = aLocation.search.substring(1);
    else
      query = aLocation.hash.substring(1);
    var args = query.split('&');
    for (var i = 0; i < args.length; ++i) {
      var arg = args[i];
      var sep = arg.indexOf(':');
      if (sep != -1) {
        var fileLines = arg.split(':');
        var htmlFileName = RTW_TraceArgs.toHtmlFileName(fileLines[0]);
        this.fFiles.push(htmlFileName);
        if (fileLines[1])
          this.fLines.push(fileLines[1].split(','));
      } else {
        sep = arg.indexOf('=');
        if (sep != -1) {
          var cmd = arg.substring(0,sep);
          var opt = arg.substring(sep+1);
          switch (cmd.toLowerCase()) {
            case "color":
              this.fColor = opt;
              break;
            case "fontsize":
              this.fFontSize = opt;
              break;
            case "initfile":
              this.fInitFile = RTW_TraceArgs.toHtmlFileName(opt);
              break;
            case "initline":
              this.fInitLine = opt;
              break;
            case "msg":
              this.fMessage = opt;
              break;
            case "block":
              this.fBlock = unescape(opt);
              break;
          }
        }
      }
    }
    if (this.fInitFile == null) {
      this.fInitFile = this.fFiles[0];
      this.fInitLine = (this.fLines[0] == null ? -1 : this.fLines[0][0]);
    }
  }

  this.getColor = function() { return this.fColor; }
  this.getFontSize = function() { return this.fFontSize; }
  this.getInitFile = function() { return this.fInitFile; }
  this.getInitLine = function() { return this.fInitLine; }
  this.getNumFiles = function() { return this.fFiles.length; }
  this.getFile = function(aIdx) { return this.fFiles[aIdx]; }
  this.getLines = function(aIdx) { return this.fLines[aIdx]; }
}


RTW_TraceArgs.toHtmlFileName = function(aFile) {
  aFile = aFile.replace(/.c$/,"_c.html");
  aFile = aFile.replace(/.h$/,"_h.html");
  aFile = aFile.replace(/.cpp$/,"_cpp.html");
  aFile = aFile.replace(/.hpp$/,"_hpp.html");
  aFile = aFile.replace(/.cc$/,"_cc.html");
  return aFile;
}

RTW_TraceArgs.instance = null;

RTW_MessageWindow = function(aWindow, aParagraph) {
  this.fWindow    = aWindow;
  this.fParagraph = aParagraph;
  
  this.print = function(msg) {
    this.fParagraph.innerHTML = msg;
    if (msg)
      this.fWindow.style.display = "block";
    else
      this.fWindow.style.display = "none";
  }
  this.clear = function() {
    this.print("");
  }
}

RTW_MessageWindowFactory = function(aDocObj) {
  this.fDocObj = aDocObj;
  this.fInstance = null;

  this.getInstance = function() {
    if (this.fInstance)
      return this.fInstance;
    if (!this.fDocObj)
      return;
      
    var table     = this.fDocObj.getElementById("rtwIdMsgWindow");
    var paragraph = this.fDocObj.getElementById("rtwIdMsg");
    var button    = this.fDocObj.getElementById("rtwIdButtonMsg");

    if (!table || !paragraph || !button)
      return null;

    obj = new RTW_MessageWindow(table,paragraph);
    button.onclick = function() { obj.clear(); }
    this.fInstance = obj;
    return this.fInstance;
  }
}

RTW_MessageWindowFactory.instance = null;
RTW_MessageWindow.factory = function(aDocObj) {
  if (!RTW_MessageWindowFactory.instance)
    RTW_MessageWindowFactory.instance = new RTW_MessageWindowFactory(aDocObj);
  return RTW_MessageWindowFactory.instance.getInstance();
}



function rtwSrcFrame() {
  return top.rtwreport_document_frame;
}
function rtwTocFrame() {
  return top.rtwreport_contents_frame;
}

function rtwGetFileName(url) {
  var slashIdx = url.lastIndexOf('/');
  var hashIdx  = url.indexOf('#', slashIdx);
  if (hashIdx == -1)
    return url.substring(slashIdx+1)
  else
    return url.substring(slashIdx+1,hashIdx);
}

function expandFileGroup(docObj, tagID) {
  if (docObj.getElementById) {
    var obj_table = docObj.getElementById(tagID);
    var o;
    while (obj_table.nodeName != "TABLE") {
      if (obj_table.parentNode) {
        obj_table = obj_table.parentNode;
      } else {
        return;
      }
    }
    if (obj_table.style.display == "none") {
      var category_table = obj_table.parentNode;
      while (category_table.nodeName != "TABLE") {
        if (category_table.parentNode) {
          category_table = category_table.parentNode;
        } else {
          return;
        }        
      }
      var o = category_table.id + "_button";
      o = docObj.getElementById(o);
      if (o && top.rtwreport_contents_frame.rtwFileListShrink) {
        top.rtwreport_contents_frame.rtwFileListShrink(o, category_table.id, 0);
      }
    }
  }
}
function setBGColorByElementId(docObj, tagID, bgColor) {
    if (bgColor == "") {
      bgColor = "TRANSPARENT";
    }
    
    if (docObj.getElementById) {
        var obj2Hilite = docObj.getElementById(tagID);
        if (obj2Hilite && obj2Hilite.parentNode)
            obj2Hilite.parentNode.style.backgroundColor = bgColor;
    }
}

function setBGColorByElementsName(docObj, tagName, bgColor) {
  if (bgColor == "") {
    bgColor = "TRANSPARENT";
  }  
  if (docObj.getElementsByName) {
    var objs2Hilite = docObj.getElementsByName(tagName);        
    for (var objIndex = 0; objIndex < objs2Hilite.length; ++objIndex) {     
        if (objs2Hilite[objIndex].parentNode)
            objs2Hilite[objIndex].parentNode.style.backgroundColor = bgColor;
    }
  }
}

function hiliteByElementsName(winObj, tagName) {
    var hiliteColor = "#aaffff";
    if (winObj.document)
        setBGColorByElementsName(winObj.document, tagName, hiliteColor);
}

function removeHiliteByElementsName(winObj, tagName) {
    if (winObj.document)
        setBGColorByElementsName(winObj.document, tagName, "");
}

function setBGColorByHash(docObj, bgColor) {    
    if (docObj.location) {
        var tagName = docObj.location.hash;
        if (RTW_Hash.instance)
            tagName = RTW_Hash.instance.getHash();
        tagName = tagName.substring(1);
        
        var codeNode = docObj.getElementById("RTWcode");
        if (tagName != null && tagName != "") {        
            if (!isNaN(tagName))
                tagName = Number(tagName) + 10;            
            setBGColorByElementsName(docObj, tagName, bgColor);
        }
   }
}

function hiliteByHash(winObj) {       
    var hiliteColor = "#aaffff";  
    if (winObj.document)    
        setBGColorByHash(winObj.document, hiliteColor);
}

function removeHiliteByHash(winObj) {
    if (winObj.document)
        setBGColorByHash(winObj.document, "");
}

function hiliteByFileName(winObj) {       
    if (!winObj.location || !winObj.document || !top.rtwreport_contents_frame)
        return;
    var hiliteColor = "#ffff99";  
    var fileName = rtwGetFileName(winObj.location.href);    
    if (top.rtwreport_contents_frame.document) {
        setBGColorByElementId(top.rtwreport_contents_frame.document, fileName, hiliteColor);
        expandFileGroup(top.rtwreport_contents_frame.document, fileName);
    }
}

function removeHiliteTOC(winObj) {    
    removeHiliteByElementsName(winObj, "rtwIdGenFileLinks");
    removeHiliteByElementsName(winObj, "TOC_List"); 
}

function tocHiliteById(id) {
    hiliteColor = "#ffff99";    
    if (top && top.rtwreport_contents_frame && top.rtwreport_contents_frame.document) {
        removeHiliteTOC(top.rtwreport_contents_frame);
        setBGColorByElementId(top.rtwreport_contents_frame.document, id, hiliteColor);
    }
}

function tocHiliteMe(winObj, linkObj, bCleanTrace) {
    hiliteColor = "#ffff99";
    if (bCleanTrace && RTW_TraceInfo.instance) {
        RTW_TraceInfo.instance.setDisablePanel(true);
        rtwRemoveHighlighting();
    }        
    removeHiliteTOC(winObj);
    if (linkObj.parentNode) {
        linkObj.parentNode.style.backgroundColor= hiliteColor;
    }
}

function docHiliteMe(winObj, elementName) {
    removeHiliteByHash(winObj);
    if (RTW_Hash.instance) {
      RTW_Hash.instance.setHash("#"+elementName);
    } else {
      RTW_Hash.instance = new RTW_Hash("#"+elementName);
    }
    hiliteByElementsName(winObj, elementName);
}

function rtwFileOnLoad(winObj) {
  
  if (winObj.location) {
    if (!RTW_Hash.instance) {
      RTW_Hash.instance = new RTW_Hash(winObj.location.hash);
    } else {
      RTW_Hash.instance.setHash(winObj.location.hash);
    }
  }
   
  hiliteByHash(winObj);
  if (top.rtwreport_contents_frame)
    removeHiliteTOC(top.rtwreport_contents_frame);
  hiliteByFileName(winObj);
  
  if (!winObj.location || !winObj.location.href || !winObj.document
      || !RTW_TraceInfo.instance)
    return;
  docObj = winObj.document;
  if (!docObj.getElementById)
    return;
  if (rtwSrcFrame())
    rtwSrcFrame().focus();
  var fileName = rtwGetFileName(winObj.location.href);
  var fileIdx = RTW_TraceInfo.instance.getFileIdx(fileName);
  if (fileIdx != null) {
    if (fileIdx != RTW_TraceInfo.instance.getCurrFileIdx())
      RTW_TraceInfo.instance.setCurrent(fileIdx,-1);
    var codeNode = docObj.getElementById("RTWcode");
    var hiliteColor = RTW_TraceArgs.instance.getColor();
    if (!hiliteColor) {
        hiliteColor = "#aaffff";
    }
    var fontSize = RTW_TraceArgs.instance.getFontSize();
    if (fontSize) {
        codeNode.style.fontSize = fontSize;
    }
    RTW_TraceInfo.instance.highlightLines(codeNode,hiliteColor);
    RTW_TraceInfo.instance.highlightFileLink(fileIdx,"#ffff99");
  }
}

function rtwGoPrev() {
  if (RTW_TraceInfo.instance && top.rtwreport_document_frame) {
    var prevfileIdx = RTW_TraceInfo.instance.getPrevFileIdx();
    var currfileIdx = RTW_TraceInfo.instance.fCurrFileIdx;
    RTW_TraceInfo.instance.goPrev();
    top.rtwreport_document_frame.document.location.href=RTW_TraceInfo.instance.getCurrentHRef();
    if (prevfileIdx == currfileIdx) {
        if (top.rtwreport_contents_frame) {
            removeHiliteTOC(top.rtwreport_contents_frame);
            hiliteByFileName(top.rtwreport_document_frame);
        }
    }
  }
}

function rtwGoNext() {
  if (RTW_TraceInfo.instance && top.rtwreport_document_frame) {
    var nextfileIdx = RTW_TraceInfo.instance.getNextFileIdx();
    var currfileIdx = RTW_TraceInfo.instance.fCurrFileIdx;
    RTW_TraceInfo.instance.goNext();
    top.rtwreport_document_frame.document.location.href=RTW_TraceInfo.instance.getCurrentHRef();
    if (nextfileIdx == currfileIdx) {
        if (top.rtwreport_contents_frame) {
            removeHiliteTOC(top.rtwreport_contents_frame);
            hiliteByFileName(top.rtwreport_document_frame);
        }
    }
  }
}

function rtwMainOnLoadFcn(topDocObj,tocDocObj,fileDocObj,aLoc,aPanel) {
  var loc;
  if (!aLoc) {
    loc = topDocObj.location;
  } else {
    loc = new Object();
    loc.hash = "#"+aLoc;
  }
    
  RTW_TraceArgs.instance = new RTW_TraceArgs(loc);
  var initPage = null;
  if (RTW_TraceArgs.instance.getNumFiles()) {
    var fileLinks = RTW_TraceInfo.getFileLinks(tocDocObj);
    var prevButton = tocDocObj.getElementById("rtwIdButtonPrev");
    var nextButton = tocDocObj.getElementById("rtwIdButtonNext");
    var panel = tocDocObj.getElementById("rtwIdTracePanel");
    RTW_TraceInfo.instance = new RTW_TraceInfo(fileLinks, prevButton, nextButton, panel);
    RTW_TraceInfo.instance.removeHighlighting();
    var numFiles = RTW_TraceArgs.instance.getNumFiles();
    for (var i = 0; i < numFiles; ++i) {
      RTW_TraceInfo.instance.setLines(RTW_TraceArgs.instance.getFile(i),RTW_TraceArgs.instance.getLines(i));
    }
    if (aPanel == false) {
      RTW_TraceInfo.instance.setDisablePanel(true);
    }
    var initFile = RTW_TraceArgs.instance.getInitFile();
    RTW_TraceInfo.instance.setInitLocation(initFile,RTW_TraceArgs.instance.getInitLine());
    initPage = RTW_TraceInfo.instance.getCurrentHRef();
  } else {
    if (fileDocObj.location && (!fileDocObj.location.href || fileDocObj.location.href == "about:blank")) {
      var summaryPage = tocDocObj.getElementById("rtwIdSummaryPage");
      if (summaryPage) {
        initPage = summaryPage.href;
      }
    }
  }
  if (RTW_TraceArgs.instance && RTW_TraceArgs.instance.fMessage) {
    var msgFile = tocDocObj.getElementById('rtwIdMsgFileLink');
    if (msgFile && msgFile.style) {
      msgFile.style.display = "block";
      msgFile.childNodes[0].style.backgroundColor = "#ffff99";
    }
    initPage = "rtwmsg.html";
  }
  if (initPage) {
    fileDocObj.location.href = initPage;
  }
}

function rtwMainOnLoad() {
  rtwMainOnLoadFcn(document,top.rtwreport_contents_frame.document,top.rtwreport_document_frame.document,null,true);
}

function rtwMainReload(location) {
  rtwMainOnLoadFcn(document,top.rtwreport_contents_frame.document,top.rtwreport_document_frame.document,location,true);
}

function rtwMainReloadNoPanel(location) {
  rtwMainOnLoadFcn(document,top.rtwreport_contents_frame.document,top.rtwreport_document_frame.document,location,false);
}

function rtwRemoveHighlighting() {
  if (RTW_TraceInfo.instance)
    RTW_TraceInfo.instance.removeHighlighting();
  if (rtwSrcFrame())
    rtwSrcFrame().focus();
}

function rtwDisplayMessage() {
  var docObj = top.rtwreport_document_frame.document;
  var msg = docObj.getElementById(RTW_TraceArgs.instance.fMessage);
  if (!msg) {
    msg = docObj.getElementById("rtwMsg_notTraceable");
  }
  if (msg && msg.style) {
    msg.style.display = "block"; 
    var msgstr = msg.innerHTML;
    if (RTW_TraceArgs.instance.fBlock) {
      msgstr = msgstr.replace("%s",RTW_TraceArgs.instance.fBlock);
    }
    msg.innerHTML = msgstr;
  }
}

function rtwPageOnLoad(id) {
    // highlight toc entry
    tocHiliteById(id);
    // restore elements state
    if (top && top.restoreState) {
        if (top.rtwreport_contents_frame && top.rtwreport_contents_frame.document)
            top.restoreState(top.rtwreport_contents_frame.document);
        if (top.rtwreport_document_frame && top.rtwreport_document_frame.document)
            top.restoreState(top.rtwreport_document_frame.document);
    }
}

window.onload=rtwMainOnLoad;

