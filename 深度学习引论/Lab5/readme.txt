# Lab 5 - Handwritten Digit to Speech Convertor

## Information

* Course: Understanding Deep Neural Networks
* Teacher: Zhang Yi
* Student:
* ID:

## Files

* `lab5.m` - the MATLAB code file for the main procedure of this lab.
* `fc.m` - the MATLAB code file for feedforward computation.
* `bc.m` - the MATLAB code file for backward computation
* `mnist_small_matlab.mat` - the MATLAB data file of handwritten digits dataset
* `audio/[0-9].wav` - the WAVE files of standard audio of digits

## Instructions

Implement forward computing and backward computing in `fc.m` and `bc.m`.
You can change the interface according to your program need.
For example, you may want to pass a function handle to specify the activation function.

The procedure is similar to Lab 4.
You can input the image either as a whole or in parts.
The target is changed from digit label to audio wave.
And you don't have an accuracy now.

Audio waves are sequence of float point decimals ranged in [-1,1].
We have cut the each audio to have the same (2983) length.
The sample rate of the audio files are 4000.

You can use `audioread()` in MATLAB to read audio files.
You can use `soundsc()` in MATLAB to play audio wave.
See the documentation for more details about these functions.

## Submission

* Submit all (3) `.m` files in a zip file. Do not attach `.mat` and `.wav` files.
* Submit to email address of TA (hujunjiescu@163.com)
* Use email title:
    ```
    DNN2018F Lab5 <student-id> <student-name>
    ```
    (Don't keep `<`, `>`, `&gt;`, or `&lt;` in the title. Just fill in your student id and your name.)
    TA will be using a filter to **throw away** any email not following such format.
* Deadline: 2018/10/12 23:59
