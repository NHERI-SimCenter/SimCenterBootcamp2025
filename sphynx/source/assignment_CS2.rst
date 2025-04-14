C: Assignments Session 2
========================


Some more problems for you to tackle. Parts should look and feel familiar from first session, though we will add more features as we go.


Problem 1: DGEMM
------------------------------------------------------
Navigate to **/assignments/C-Session2/matMul**. Instead of a single file, there are multiple files. One of these files, **BlasDGEMM.c**, invokes the BLAS dgemm function and requires that the application be linked to the **BLAS** library. Compiling and linking the applications would require you to find the path to the blas libraries. In addition the multiple .c files would require multiple compilation commands. Compiling this version requires multiple steps:

.. code::

	gcc myDGEMM.c -c
	gcc blasDGEMM.c -c	
	gcc matMul.c myDGEMM.o blasDGEMM.o -lm -/pathtoblaslibrary -o matMul

And you can run the executable as

.. code::

	./matMul

Imagine doing this for many more files, usually tens to hundreds.  That would be painstaking and
inefficient and very error prone.  Software engineers developed several tools to simplify and automate the compile
process.  One of those tools is **cmake**, a member of the **make** family of tools.  You find a
configuration file names **CMakeList.txt** in the source folder. The configuration
file is a plain text file, so you can and should check out how it is written.

The compile process now becomes 

1. a configuration step - done only once or every time you are adding a file to the project.  Inside the
source folder, execute

.. code::

	$ mkdir build
	$ cd build
	$ cmake ..
	$ cmake --build .


This will check your system for compilers and other development tool and create a **Makefile** in each
source folder. 

.. note:: 

    Placing the compile files into a *build* folder makes cleanup easier: simply delete
    the entire *build* folder when done.  It can be regenerated easily using the above procedure.

2. From now on, every time you make changes to any of the files within your project, simply
type

.. code::

	$ cmake --build .

to recompile all portions necessary and link all parts to one executable.  That process remains exactly the
same regardless of the number of files in your project.  Give it a try and see how convenient this is
especially for projects provided by somebody else.

Now that you can compile the **matMul** application, you will find it does not work! You are required to fix the **matMul.c** program to allocate memory for the A, B, C and C1 arrays. These arrays are double arrays to hold square, n by n, matrices that are required to be stored in column major order. Some code is required lines 29 through 32. You should also throw in **4** lines ariund line 59.

.. literalinclude:: ./assignments/c2/matMul.c
   :language: c
   :linenos:   

After fixing the matMul.c file, you need to edit the **myDGEMM.c** file and place in their code to perform the matrix-matrix operation: C = C + A * B;

.. math:: 

   c_{ij}= c_{ij} + a_{i1} b_{1j} + a_{i2} b_{2j} +\cdots+ a_{in} b_{nj} = c_{ij} + \sum_{k=1}^n a_{ik}b_{kj}

.. literalinclude:: ./assignments/c2/myDGEMM.c
   :language: c
   :linenos:   


.. note::

   The CMake process created another executabble, **benchmark**. If you run it you will see how your implementation compares in performance against the vendor supplied blas function. It is probably a pretty bad comparison. Try improving the performance. You can play with different compile options, or a revised algorithm, e.g. black matrix-multiply. 
      
   

Problem 2: Reading From a CSV file, Memory Allocation & Writing to Binary
-------------------------------------------------------------------------


Reading of data from files and placing them into containers such as Vectors is easy if you know the size of the data you are reading. If this is unknown the problem becomes more tricky. The solution presented on slide 22 worked for a small number of inputs, but failed with a segmentation fault for larger problems. You are to fix the problem. A copy of the offending file **file3.c** has been placed in the directory binaryFile along with two files. The program can handle the first **small.txt**, it will fail with the second **big.txt**. Can you make the program work. The solution will test your understanding of file I/O,  memory management and pointers.

Initial code is provided in the  **/assignments/C-Session2/binaryFile** directory.

At end of the program, you are asked to modify the code so that the results of the two vectors are ouput to a binary file. Output the contents of **vector1** followed by **vector2**.

The **file3.c** is as shown below. You need to put some code to replace comment at the line 41.

.. literalinclude:: ./assignments/c2/file3.c
  :language: c
  :linenos:

The **small.txt** file is as shown below.

.. literalinclude:: ./assignments/c2/small.txt
  :linenos:     

.. note::
   
   No cmake or Makefile has been provided. You can compile the file with icc or whatever compiler you are using. The program takes two inputs, the file to read and the file to write. To compile and test the program, issue the following at the terminal prompt. When done compare the file sizes of the binary file to the text file.


   .. code::

      icc file3.c -o file3
      ./file2 small.txt
      ./file2 big.txt


.. note::
   
   Give some thought as to how you would open the file and read back in the two vectors. If you have some time, write a program to do and have that program write the contents of the binary files to a csv file.
