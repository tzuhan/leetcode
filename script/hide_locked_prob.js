/*Use tampormonkey to execute this script on leetcode*/
// ==UserScript==
// @name         Leetcode-hide-locked-problems
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  Hide locked problems
// @author       Han
// @match        https://leetcode.com/problemset/*
// @match        https://leetcode.com/tag/*
// @grant        none
// @require      http://code.jquery.com/jquery-latest.js
// ==/UserScript==

(function() {
        'use strict';
            var str = $('#brief_stats strong').text();
                var denominator = str.split(" /")[1];
                    var numerator = str.split(" /")[0];
                        var hide_problems = $('tr').has('.fa.fa-lock');
                            hide_problems.css('display', 'none'); //css('display', 'none;') == .hide()
    denominator -= hide_problems.length;
        $('#brief_stats strong').text(numerator+" / "+denominator.toString());
            
})();
