// Import only necessary modules/functions
const { contextBridge, ipcRenderer } = require('electron');
const fs = require('fs');
const path = require('path');
//const ffi = require('ffi-napi');
//const spawn = require('child_process').spawn;
//jsonStreamStringify: require('json-stream-stringify')
// Expose specific modules/functions to the renderer process
contextBridge.exposeInMainWorld('electron', {
  node: () => process.versions.node,
  chrome: () => process.versions.chrome,
  electron: () => process.versions.electron
});
contextBridge.exposeInMainWorld('fs', fs);
contextBridge.exposeInMainWorld('path', path);
contextBridge.exposeInMainWorld("ipcRenderer",ipcRenderer);

// Optional: Add any other code you need to run in the preload script
window.ipcRenderer = ipcRenderer;
window.addEventListener('DOMContentLoaded', () => {
  const replaceText = (selector, text) => {
    const element = document.getElementById(selector);
    if (element) element.innerText = text;
  }
  
  for (const type of ['chrome', 'node', 'electron']) {
    replaceText(`${type}-version`, process.versions[type]);
  }
});
