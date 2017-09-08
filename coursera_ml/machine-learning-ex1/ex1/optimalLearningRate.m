data = load('ex1data2.txt');
y = data(:, 3);
m = length(y);
X = [ones(m,1), data(:, 1:2)];
num_iters = 50;


for factor = 1:5,
	theta = zeros(3,1)	
	alpha = 0.9/(3**factor)
	[theta, J_history]  = gradientDescentMulti(X, y, theta, alpha, num_iters)

	fprintf('leny: %f\n', length(J_history))
	fprintf('lenx: %f\n', length(1:num_iters))

	plot(1:num_iters, J_history, 'b')

end;

