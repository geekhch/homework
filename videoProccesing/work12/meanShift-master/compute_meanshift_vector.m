%-------------------------------------
function z = compute_meanshift_vector(imPatch, prev_center, weights)
[h,w] = size(imPatch);
coordinate = [prev_center(1)-w/2 prev_center(2)-h/2];

[x,y] = meshgrid(coordinate(1):1:w+coordinate(1)-1, coordinate(2):1:h+coordinate(2)-1);

x_mass = sum(sum(x.*weights / sum(weights(:))));
y_mass = sum(sum(y.*weights / sum(weights(:))));

z = [x_mass, y_mass];

end
