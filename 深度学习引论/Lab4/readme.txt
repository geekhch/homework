# Lab 4 - Handwritten digits recognition

## Information

* Course: Understanding Deep Neural Networks
* Teacher: Zhang Yi
* Student:
* ID:

## Files

* `lab4.m` - the MATLAB code file for online BP algorithm, with XOR-worms example for evaluation
* `fc.m` - the MATLAB code file for feedforward computation. **NOTICE**, the parameter of this function is changed.
* `bc.m` - the MATLAB code file for backward computation
* `mnist_small_matlab.mat` - the MATLAB data file of handwritten digits dataset

## Instructions

Implement forward computing and backward computing in `fc.m` and `bc.m`.
**NOTICE**, the parameter of forward computing is changed to fit this example.
You may need to debug together with `lab4.m`.

Follow the code example in the courseware slides to finish `lab4.m`.

1. prepare the data set
2. choose parameters
3. define network architecture
4. initialize weights
5. train
6. save model
7. testing

Capture the cost function plot and the accuracy plot using following parameters:
```
alpha = 1;
max_iter = 300;
mini_batch = 100;
```

## Submission

* Submit all (3) `.m` files, and the 2 plots (as `.jpg` files) in a zip file. Do not attach `.mat` file.
* Submit to email address of TA (hujunjiescu@163.com)
* Use email title:
    ```
    DNN2016F Lab4 <student-id> <student-name>
    ```
    (Don't keep `<`, `>`, `&gt;`, or `&lt;` in the title. Just fill in your student id and your name.)
    TA will be using a filter to **throw away** any email not following such format.
* Deadline: 2016/10/13 23:59
