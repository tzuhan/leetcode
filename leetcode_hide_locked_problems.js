// ==UserScript==
// @name         Leetcode hide locked problems
// @namespace    https://github.com/tzuhan
// @version      1.1
// @description  hide locked problems in leetcode, updated at 10/28/2016 for leetcode page's ajax rendering problem
// @author       You
// @match        https://leetcode.com/problemset/*/*
// @grant        none
// @require     http://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js
// jshint esnext: true
// ==/UserScript==

setTimeout(function() {
    // Your code here...
    'use strict';
    const lock = $("tr:has(i.fa-lock)"); //tr's decendents which is elemenet i and has fa-lock class
    console.log(`locked problem numbers: ${lock.length}`);
    lock.hide();
    const p = $("#welcome strong"); //id #welcome element's descendant which element is <strong> ("anscentor descendant")
    if(p.length>0){
        const[solved, total] = p.text().split('/').map((x)=>+x); // +x => set to int, map pass each element to result array.
        const real_total = total - lock.length;
        p.text(`${solved} / ${real_total}`);
    }
}, 300); //since leetcode use ajax to create web page, if we exceute this script upon opening the website, the function will be launched before html elements are set. Hence use setTimeOut to wait for the page being rendered.
