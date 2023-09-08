document.addEventListener('DOMContentLoaded', function () {
    const { electron } = window;
    const { ipcRenderer } = window;
    let container = document.querySelector('.components');
    // const ffi = electron.ffi;
    const searchButton = document.getElementById('searchButton');
    const andButton = document.getElementById('andButton');
    const orButton = document.getElementById('orButton');
    const fromDateInput = document.getElementById('fromDate');
    const toDateInput = document.getElementById('toDate');
    const today = new Date();
    const lastWeek = new Date();
    const fs = window.fs;

    lastWeek.setDate(today.getDate() - 7);

    flatpickr(fromDateInput, {
        dateFormat: 'm/d/Y',
        defaultDate: lastWeek,
        onChange: function (selectedDates, dateStr, instance) {
            fromDateValue = selectedDates[0];
        }
    });

    flatpickr(toDateInput, {
        dateFormat: 'm/d/Y',
        defaultDate: today,
        onChange: function (selectedDates, dateStr, instance) {
            toDateValue = selectedDates[0];
        }
    });

    function isToday(userDate) {
        const userDateObj = new Date(userDate);
        const currentDate = new Date();
        return (
            userDateObj.getFullYear() === currentDate.getFullYear() &&
            userDateObj.getMonth() === currentDate.getMonth() &&
            userDateObj.getDate() === currentDate.getDate()
        );
    }

    function wildcardMatch(str, pattern) {
        const escapedPattern = pattern.replace(/[-\/\\^$*+?.()|[\]{}]/g, '\\$&');
        const regex = new RegExp(escapedPattern);
        return regex.test(str);
    }

    function getDatesBetween(startDate, endDate) {
        const dateArray = [];
        const currentDate = new Date(startDate);
        const targetDate = new Date(endDate);

        while (currentDate <= targetDate) {
            const dateString = currentDate.toLocaleDateString();
            let obj = {
                fileDate: dateString
            };
            dateArray.push(obj);
            currentDate.setDate(currentDate.getDate() + 1);
        }

        return dateArray;
    }

    andButton.addEventListener('click', function () {
        var inputElement = document.getElementById('searchFor');
        var currentValue = inputElement.value;

        if (currentValue.trim() !== '') {
            inputElement.value = currentValue + ';';
        }
    });

    orButton.addEventListener('click', function () {
        var inputElement = document.getElementById('fileName');
        var currentValue = inputElement.value;

        if (currentValue.trim() !== '') {
            inputElement.value = currentValue + ';';
        }
    });

    document.getElementById('searchResultsItems').addEventListener('click', function (event) {
        const linkButton = event.target.closest('.linkButton');

        if (linkButton) {
            const filePath = linkButton.getAttribute('data-file-path');
            ipcRenderer.send('open-local-file', filePath);
        }
    });

    function searchFileForTerm(filePath, searchTerm) {
        try {
            const fileContent = fs.readFileSync(filePath, 'utf8');
            const lines = fileContent.split('\n');

            if (searchTerm.includes(';')) {
                const searchSplit = searchTerm.split(';');
                if (searchSplit.length > 1) {
                    for (const searchTerms of searchSplit) {
                        if (!fileContent.includes(searchTerms)){
                            return null;
                        }
                    }
                return "All search terms present";
                }
            } else {
                for (const line of lines) {
                    if (line.includes(searchTerm)) {
                        return line;
                    }
                }
            }
            return null;
        } catch (error) {
            console.error('Error:', error);
            return null;
        }
    }

    function getFileSizeInKB(filePath) {
        try {
            const stats = fs.statSync(filePath);
            const fileSizeInBytes = stats.size;
            const fileSizeInKB = fileSizeInBytes / 1024;
            return Math.round(fileSizeInKB);
        } catch (error) {
            console.error('Error getting file size:', error.message);
            return -1;
        }
    }

    function searchOutput(dateFromGUI, isToday, fileNameInput) {
        const searchFor = document.getElementById('searchFor').value;
        const fileList = fileNameInput.split(';');
        let fileNameMatch = [];
        let dataDump = [];
        const todayLoc = 'R:/';
        const archiveLoc = 'R:/Archive/';
        //const todayLoc = 'R/';
        //const archiveLoc = 'R/Archive/';
        const date = new Date(dateFromGUI);
        const formattedDate = formatDate(date);

        if (isToday) {
            const todayFiles = getFiles(todayLoc);
            const todayMatches = findMatchingFiles(todayFiles, fileList);
            console.log("findMatchingFiles");
            fileNameMatch.push(...todayMatches);

            fileNameMatch.forEach(file => {
                if (searchFor.length > 0) {
                    const lineMatch = searchFileForTerm(todayLoc + file, searchFor);
                    if (lineMatch !== null) {
                        const corLineMatch = htmlEncode(lineMatch);
                        dataDump.push({
                            fullLink: todayLoc + file,
                            linkBut: file,
                            fileDate: dateFromGUI,
                            fileSize: getFileSizeInKB(todayLoc + file),
                            snippet: corLineMatch
                        });
                    } else {
                        console.log('Term not found in the file.');
                    }
                } else {
                    dataDump.push({
                        fullLink: todayLoc + file,
                        linkBut: file,
                        fileDate: dateFromGUI,
                        fileSize: getFileSizeInKB(todayLoc + file),
                        snippet: "No search term"
                    });
                }
            });
            return dataDump;

        } else {
            let fileYear = date.getFullYear();
            fileYear = fileYear + '/';
            const dateFolder = path.join(archiveLoc, fileYear);
            const archiveFiles = getFiles(path.join(archiveLoc, formattedDate));
            if (archiveFiles.length > 0) {
                const archiveMatches = findMatchingFiles(archiveFiles, fileList);
                console.log(path.join(archiveLoc, formattedDate));
                fileNameMatch.push(...archiveMatches);
                fileNameMatch.forEach(file => {
                    if (searchFor.length > 0) {
                        const lineMatch = searchFileForTerm(archiveLoc + formattedDate + file, searchFor);
                        if (lineMatch !== null) {
                            const corLineMatch = htmlEncode(lineMatch);
                            dataDump.push({
                                fullLink: archiveLoc + formattedDate + file,
                                linkBut: file,
                                fileDate: dateFromGUI,
                                fileSize: getFileSizeInKB(archiveLoc + formattedDate + file),
                                snippet: corLineMatch
                            });
                        } else {
                            console.log('Term not found in the file.');
                        }
                    } else {
                        dataDump.push({
                            fullLink: archiveLoc + formattedDate + file,
                            linkBut: file,
                            fileDate: dateFromGUI,
                            fileSize: getFileSizeInKB(archiveLoc + formattedDate + file),
                            snippet: "No search term"
                        });
                    }
                });
                return dataDump;
            } else {
                const archiveFiles2 = getFiles(path.join(dateFolder, formattedDate));
                const archiveMatches2 = findMatchingFiles(archiveFiles2, fileList);
                fileNameMatch.push(...archiveMatches2);
                fileNameMatch.forEach(file => {
                    if (searchFor.length > 0) {
                        const lineMatch = searchFileForTerm(dateFolder + formattedDate + file, searchFor);
                        if (lineMatch !== null) {
                            const corLineMatch = htmlEncode(lineMatch);
                            dataDump.push({
                                fullLink: dateFolder + formattedDate + file,
                                linkBut: file,
                                fileDate: dateFromGUI,
                                fileSize: getFileSizeInKB(dateFolder + formattedDate + file),
                                snippet: corLineMatch
                            });
                        } else {
                            console.log('Term not found in the file.');
                        }
                    } else {
                         dataDump.push({
                            fullLink: dateFolder + formattedDate + file,
                            linkBut: file,
                            fileDate: dateFromGUI,
                            fileSize: getFileSizeInKB(dateFolder + formattedDate + file),
                            snippet: "No search term"
                        });
                    }
                });
                return dataDump;
            }
        }
        return dataDump;
    };

    function formatDate(date) {
        const year = String(date.getFullYear());
        const month = String(date.getMonth() + 1).padStart(2, '0');
        const day = String(date.getDate()).padStart(2, '0');
        return `${month}${day}${year}/`;
    };

    function getFiles(directory) {
        try {
            const files = fs.readdirSync(directory);
            console.log("\nCurrent directory filenames:");
            files.forEach(file => {
                console.log(file);
            });
            return files;
        } catch (error) {
            console.log(`Error reading directory ${directory}: ${error.message}`);
            return [];
        }
    }

    function findMatchingFiles(fileList, patterns) {
        console.log(`findMatchingFiles(${fileList}, ${patterns})`);

        const matchingFiles = [];

        for (const pattern of patterns) {
            for (const fileName of fileList) {
                if (wildcardMatch(fileName, pattern)) {
                    console.log(`Matched '${fileName}' with pattern '${pattern}'`);
                    matchingFiles.push(fileName);
                }
            }
        }

        return matchingFiles;
    }

    searchButton.addEventListener('click', searchButtonClick);

    function htmlEncode(text) {
    const map = {
        '&': '&amp;',
        '<': '&lt;',
        '>': '&gt;',
        '"': '&quot;',
        "'": '&#039;'
    };

    return text.replace(/[&<>"']/g, function (m) {
        return map[m];
    });
}


 function searchButtonClick() {
    const loadingAnimation = document.getElementById("loader");
    searchResultsItems.innerHTML = '';
    loadingAnimation.style.display = "block"; // Display the animation
    container.classList.remove("visible");
    container.classList.add("searching");
    //document.body.style.backgroundColor = "#58646A";
   // document.getElementById("searchResults").classList.remove("visible");
//    setTimeout(() => {  //timeout test for loading screen

    const fileNames = document.getElementById("fileName").value;
    const jDates = getDatesBetween(document.getElementById("fromDate").value, document.getElementById("toDate").value);
    let results = [];
    console.log('Button Clicked');

    jDates.forEach((jDateItem) => {
        console.log(jDateItem);
        if (isToday(jDateItem.fileDate)) {
            console.log("Today");
            const todayResults = searchOutput(jDateItem.fileDate, true, fileNames);
            results.push(...todayResults);
        } else {
            console.log("Not Today");
            const nonTodayResults = searchOutput(jDateItem.fileDate, false, fileNames);
            results.push(...nonTodayResults);
        }
    });

    if (Array.isArray(results)) {
        console.log("results is an array");
        results.forEach(resultItem => {
            const resultDiv = document.createElement("div");
            resultDiv.className = "searchResults"; // Initially hidden due to CSS class
            resultDiv.innerHTML = `<div class="linkButton linkButton__primary" data-file-path="${resultItem.fullLink}"><p>${resultItem.linkBut}</p></div><div class="date_size"><div class="date_size__dateResult"><p>${resultItem.fileDate}</p></div><div class="date_size__sizeResult"><p>${resultItem.fileSize}KB</p></div></div><div class="preview"><p>${resultItem.snippet}</p></div></div>`;
            searchResultsItems.appendChild(resultDiv);

            // Adding a small delay before adding the "visible" class to trigger the animation
            setTimeout(() => {
                container.classList.add("visible");
            }, 50 * results.indexOf(resultItem));
            setTimeout(() => {
                container.classList.remove("searching");
            }, 50 * results.indexOf(resultItem));
            setTimeout(() => {
                resultDiv.classList.add("visible");
            }, 100 * results.indexOf(resultItem));
        });
    } else {
        console.log("results is not an Array");
    }
    console.log("SearchButtonClick complete");
    loadingAnimation.style.display = "none"; // Hide the animation
//    document.body.style.backgroundColor = "#E4EBF5";
//     }, 5000);//end of loading screen test comment out later
}
});
