# Line Code Interview

#### Line messenger team:


1. give a and b return a*b

    __ANS__: easy.  

2. give width and length of a rectangle, return its area

    __ANS__: easy.

3. give a direct graph and a search depth, find if there exist a cycle which length<= depth.

    input:

        4 //four nodes
        0100
        1001
        0011
        0110
        3 //search depth

    __Ans__: straight way: direct graph construction and then BFS.

    still thinking...


4. create a data structure and algorithm can do the following task

        add 5 2   //add(key, value)
        get 5     //get(key), return value of the key if exist, -1 if not
        remove 5  //remove(key), return value of the key if exist, -1 if not.
        evict     //remove last element used by get or add, return value or -1 if not exist.


    __Ans__: use hash table(unordered_map), the most need-concerned operation is evict


5. Implement an data structure and algorithm that can do the following task

        add 4
        min    //return current minimum of all element
        remove // remove the oldest element added

    __Ans__:

    one way of doing this is to create double stacks to implement a queue,  
    the other way is use an array & a min_array,    
    remove first element=> move pointer head to next element,   
    add => append element to array,     
    update min_array => min_array[i] = min(array[head] to array[i]).

    (__Hint__: store to left, if "remove" is called, push all elements to right.    
    Update min_stack and then pop the first element,    
    and one left min variable and a right min_stack to store the right local minimum.)
 
 
 
---
    
    
    

### Server team test:

1. print reverse word order, no heading or trailing space

   input:   

        N // n lines
        hello world
        bye this world

   output:  

        world hello
        world this bye

    __Ans__: c++'s input output sucks lol


2. leetcode No.300 longest increasing sequence.

   input:   

        6 1 5 2 9

   output   

        1 5 9
    __Ans__: n

3. given x y z, output x^y%z
    __Ans__:

        for(int i=0;i<y; i++){
            x = x * x % z;
        }
