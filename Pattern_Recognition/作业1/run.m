clc; clear;
n = 1e4;
sample = getSamples(n);
f = subplot(2,2,1);
f.XLabel.String='1e4';
hist(sample,n);
clear sample;

n = 1e5;
sample = getSamples(n);
f = subplot(2,2,2);
f.XLabel.String='1e5';
hist(sample,n)
clear sample;

n = 1e6;
sample = getSamples(n);
f = subplot(2,2,3);
f.XLabel.String='1e6';
hist(sample,n)
clear sample;

n = 5e6;
sample = getSamples(n);
f = subplot(2,2,4);
f.XLabel.String='5e6';
hist(sample,n)
clear sample;