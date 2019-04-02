function [ ret ] = Uniform( x1,x2 )
    ret = int16(rand*(x2-x1)+x1);
end