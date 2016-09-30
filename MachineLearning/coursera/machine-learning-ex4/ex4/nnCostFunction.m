function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
%
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.
%
% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%

% Transform y into dummy variables

y_matrix = eye(num_labels);
y = y_matrix(y,:); % see https://goo.gl/mQ0v3U
size(y);
% Cost function without regularization

% FEEDFORWARD
% Add bias to input
a1 = [ones(m,1) X]; % -> 5000 x 401

% Compute activation a2
z2 = a1 * Theta1'; 
a2 = sigmoid(z2);   % -> 5000x25 

% Add bias to a2
a2 = [ones(size(a2,1),1) a2];   % 5000x26

% Compute activation a3
z3 = a2 * Theta2';   % 5000x10
a3 = sigmoid(z3);    % 5000x10

% Compute Ouput h
h = a3;

% Compute Cost
J = 0;

% Noob code:
% for k = 1:num_labels

%    J = J + ( -y(k,:) * log(h(:,k)) - (1 - y(k,:))*log(1 - h(:,k)));
% end

% LessNoob
J = 1 / m * sum(sum((-y.*log(h) - (1-y).*log(1-h))));


% Add regularization term for the 1,...,l layers
% Also exclude Biases 
reg1 = sum(sum(Theta1(:,2:end).^2));
reg2 = sum(sum(Theta2(:,2:end).^2)); 

J =  J + lambda/(2*m) * ( reg1 + reg2 );




% Backprop
Delta1 = zeros(size(Theta1));
Delta2 = zeros(size(Theta2));
for t = 1:m
    % use already computed values by cost function code above
    a1_loop = a1(t,:);
    a2_loop = a2(t,:);
    z2_loop = z2(t,:); 
    a3_loop = h(t,:);
    
    % Compute error from ouput layer
    delta3 = (a3_loop - y(t,:));
    
    % Hidden layer l=2 now
    z2_loop = [1  z2_loop];
    delta2 =  delta3 * Theta2 .* sigmoidGradient(z2_loop);
    
    %size(delta3)
    %size(a2_loop')
    % Accumulate Gradient
    Delta1 = Delta1 +  delta2(2:end)' * a1_loop;
    Delta2 = Delta2 + delta3' * a2_loop;
end


Theta1_grad = 1/m * Delta1;
Theta2_grad = 1/m * Delta2;

% Add Regularization 
Theta1_noBias = [ zeros(size(Theta1, 1), 1) Theta1(:,2:end) ];
Theta2_noBias = [ zeros(size(Theta2, 1), 1) Theta2(:,2:end) ];
Theta1_grad = (1 / m) * Delta1 + (lambda / m) * Theta1_noBias;
Theta2_grad = (1 / m) * Delta2 + (lambda / m) * Theta2_noBias;


% -------------------------------------------------------------------------
% =========================================================================


% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end