# Learning Notes


# JS
## Scope and Closure notes

 https://toddmotto.com/everything-you-wanted-to-know-about-javascript-scope/

### Closure
 **Define a function object**
 ```javascript
 var sayHello = function (name) {
       var text = 'Hello, ' + name;
         return function () {
                 console.log(text);
                   };
 };
 ```


 ```javascript
 sayHello('Test');
 ```
 **this return the object itself. so nothing printed**

 ```javascript
 sayHello('Test')();
 ```
 **Use () to invoke the returned function.** 

 **The variables in the returned function cannot be accessed through outside**


# Python
 
