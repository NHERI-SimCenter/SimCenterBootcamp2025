C: Assignments Session 3
========================


Some more problems for you to tackle. Parts should look and feel familiar from first session, though we will add more features as we go.


Problem 1: Using structures
---------------------------

The implementation of :code:`StressTransform()` was intentionally done a bit clumsy, just the way a beginner might
write it. Your task in this exercise is to create a structure 

.. code::

	typedef struct stress {
		double sigx;
		double sigy;
		double tau;
	} STRESS ;

and modify the code from the previous exercise to utilize the much easier to read data structure provided
by this :code:`struct`.  Use the code skeleton provided in **/assignments/C_Session3/stressTransformationStruct** to develop that
code.  The included :code:`CMakeList.txt` shall be used to compile your code.

.. note::

   Your modified :code:`StressTransform(...)` will require a pointer to a :code:`STRESS` type object.  The
   way to achieve that in an efficient manner is to use a :code:`typedef struct stress {...} STRESS ;`.

   In addition, inside the function that receives the pointer to a structure, assigning a new value to
   entries in such a structure requires the syntax   

   .. code::

      void StressTransform(STRESS stressIn, STRESS *stressOut, ....) {
	...
	stressIn->sigx = ... ;
      }

   This replaces the form

   .. code::

      *sigx = ... ;

   used for scalar-valued arguments.

   


Problem 2: Writing data for use by other programs: CSV
-----------------------------------------------------

While C is very powerful for numeric computations, it can be impractical to generate graphs or fancy
images using the computed values.  A more efficient way is to use C to do the analysis, write results to
an easily readable file, and use specialized tools for the post-processing.  One common and simple format
is **CSV** (comma-separated-values), which van be read easily by MATLAB, python, or Excel.  


**Your task**: modify the code given in **/assignments/C-Session3/stressTransformFile/ex2-3/** to

1. Take one argument :math:`\Delta\theta` in degrees after the name of the executable, defining the increment at
which transformed stress values shall be written:

.. code::

	$ Exercise2-3 5.0

The format of the output shall be for one angle per line, organized as follows:


.. code::

	theta, sigma_x, sigma_y, tau_xy
	...

Output shall commence until an angle of :math:`180^\circ` has been reached or exceeded.

Once your code outputs the information, run it once more and save the results to a file names
**list.csv** (make sure to add the spaces around the '>')

.. code::

	$ Exercise2-3 5.0 > list.csv

.. note::

      We have changed the definition of a STRESS variable. It now include a pointer. We are asking you for each degree to create a new variable using malloc, determine its values using the stressTransofrm function, and add it to the results list.
      
      .. code::

	   typedef struct stress {
	         	double sigx;
		        double sigy;
		        double tau;
			struct stress *next;
	   } STRESS ;

       We have changes the use
.. note::


	
    You may want to download the file **list.csv** to your local computer before trying the next step, for it
    will require access to your display.  That file can be opened in Excel and plotted there.  A more
    efficient way is to prepare some nice plotting code, such as the provided :code:`plotter.py`.  In the same
    folder where you placed **list.csv** run

    **Windows 10**

    .. code::

	    >> python.exe plotter.py


    **MacOS** or **Linux**

    .. code::

	    $ python3 plotter.py
	    
    Isn't that nice?
   


Problem 3: Writing to a binary file
-----------------------------------

Modify the code generated in the previous exercise to write a binary file named *mohrcircle.dta* instead
of the formatted ASCII data.  The data shall be exported in clocks composed of :code:`double theta`
followed by a block of :code:`STRESS` (or the three components of stress as :code:`double`).

You may be working of your code or use the provided code skeleton in **/assignments/C-Session3/stressTensorFile/ex2-4**.

This time, your code should be totally silent on execution.  The only sign of success will be the creation
of the data file. For the next steps, run your program with the following parameters:

.. code::

	$ Exercise2-4 5.0


.. note::

    How large do you expect the binary file to be?  Discuss, predicts, and check using

    .. code::

	    $ ls -l mohrcircle.dta

    You should be able to predict the **exact** number (to the byte!).


.. note::

    This problem comes with validation code, something worth developing every time you are working on
    software that will be modified over an extended period of time and/or by multiple people.

    The validation consists of (1) a C code :code:`parse.c` which reads the binary file and outputs its
    contents to a **CSV** file, and (2) a shell script :code:`validate.sh` that attempts to run the
    validation code and compares the output generated from your binary file to an output generated by a
    correct code.

    Run the validation script as

    .. code::

	$ sh ./validate.sh

    and check its feedback. (That script may not run on all platforms.)
    
.. note::

    Binary files are not readable by traditional ASCII editors (text editors).  Doings so, usually shows
    some unintelligible scramble of characters, sometimes leaving your terminal in an unusable state.

    However, you may view binary files using a *hex-dump* utility.  That approach may help you understand
    and recover the structure of a binary file (though it still requires some practice and skill and
    **luck**).  You may try such a tool on your binary file using

    .. code::

	$ xxd mohrcircle.dta | less

    where the :code:`| less` pipes the output in a pager utility that allows you to search the output,
    jump pages forward and backward, or move to any specific line.  Press :code:`q` to exit this utility.

