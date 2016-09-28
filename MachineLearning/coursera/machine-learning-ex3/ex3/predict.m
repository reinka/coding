function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);

% You need to return the following variables correctly 
p = zeros(size(X, 1), 1);

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%
% Add bias 
X = [ones(m, 1) X];
% Theta1 = [ones(1,size(Theta1,2))] nvm Theta1 contains it already...

% Compute activation of hiden layer
z2 = X*Theta1';
a2 = sigmoid(z2);
% Add bias
a2 = [ones(m,1) a2];
h = sigmoid(a2 * Theta2');

% Extract digit with max probability and us this as a prediction
% since the p-values are in columns ranging form 1-10 we can just
% use the according column index as our label prediction 
[p_value, p] = max(h, [], 2);




% =========================================================================


end
