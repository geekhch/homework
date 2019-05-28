%-------------------------------------
function k = compute_bhattacharyya_coefficient(p,q)
    k = sum(sqrt(p.*q));
end