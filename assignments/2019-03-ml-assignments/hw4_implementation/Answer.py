import numpy as np
np.random.seed(428)

"""
*** This is where you write your answers ***

- Write your answers ONLY in here. We will grade ONLY with this file.
- ***** Write your answers in 'EDIT HERE' part ONLY!!!!! *****

- Read instructions carefully and write your answers.

- Please do not code any other functionality other than what is said to do. 
  You will not get the same results, otherwise. (Ask through e-mail or icampus note)
  ex) shuffle data every epoch (You don't need to care this. But you can try personally.)
  ex) set/change random seed (I've already done it.)

*** 이곳에 정답을 적어주세요 ***

- 여기에'만' 정답을 적어주세요. 이 파일만으로 과제가 채점됩니다.
- ***** 'EDIT HERE'라고 되어있는 곳에만 코드를 넣어주세요. *****

- 설명을 자세히 읽고 답을 적으세요.

- 명시되어있는 기능 이외의 다른 기능을 추가하지마세요. 
  정답 결과와 같은 결과가 나오지 않을 수 있습니다. (문의는 쪽지 혹은 이메일로 주세요)
  ex) 매 epoch에 데이터를 섞는다. (신경쓰지 않으셔도 됩니다. 물론 과제 이외에 개인적인 실험은 하셔도 좋습니다.)
  ex) Random seed를 설정한다/바꾼다. (이미 설정 해놓았습니다.)
"""

# ============================ Perceptron ==============================

def sign(z):
    """
    Sign function for Perceptron
    sign(z) = 1 if z > 0, -1 otherwise.

    [Inputs]
        z : input for sign function in any shape
    [Outputs]
        sign_z : sign value for z

    """
    sign_z = None
    # =============== EDIT HERE ===============

    sign_z = np.zeros_like(z)

    dim = len(z.shape)

    if dim == 1:
        for i in range(0, z.shape[0]):
            if z[i][j] > 0:
                sign_z[i] = 1
            else:
                sign_z[i] = -1
    elif dim == 2:
        for i in range(0, z.shape[0]):
            for j in range(0, z.shape[1]):
                if z[i][j] > 0:
                    sign_z[i][j] = 1
                else:
                    sign_z[i][j] = -1

    # =========================================
    return sign_z

class Perceptron:
    def __init__(self, num_features):
        # NOTE : In this assignment, weight and bias are separated. Be careful.
        self.W = np.random.rand(num_features, 1)
        self.b = np.random.rand(1)

    def forward(self, x):
        """
        Forward path of Perceptron (single neuron).
        x -- (weight, bias) --> z -- (sign function) --> sign(z)

        [Inputs]
            x : input for perceptron. Numpy array of (N, D)
        [Outputs]
            out : output of perceptron. Numpy array of (N, 1)
        """
        out = None
        if len(x.shape) < 2:
            x = np.expand_dims(x, 0)
        # =============== EDIT HERE ===============

        # x -- (weight, bias) --> z
        z = np.matmul(x, self.W) + self.b
        # z -- (sign function) --> sign(z)
        y = sign(z)

        out = y

        # =========================================
        return out

    def stochastic_train(self, x, y, learning_rate):
        num_data = x.shape[0]
        """
        Stochastic Training of perceptron 
        Perceptron Stochastic Training updates weights on every data (not batch)
        Training ends when there is no misclassified data.
        See Lecture Notes 'W09 Neural network basics'
        Again, Do not implement funtionalities such as shuffling data or sth. 

        [Inputs]
            x : input for perceptron. Numpy array of (N, D)
            y : label of data x. Numpy array of (N, )
            learning_rate : learning rate.
        
        [Outputs]
            None
        """
        while True:
            # Repeat until quit condition is satisfied.
            quit = True

            for i in range(num_data):
            # =============== EDIT HERE ===============

                # Finding and incorrect sample
                y_expected = self.forward(x[i])
                if y_expected != y[i]:
                    quit = False
                    # Updating the weight W and the bias b
                    for j in range(x.shape[1]):
                        self.W[j] = self.W[j] + (learning_rate * (y[i] * x[i][j]))
                    self.b = self.b + (learning_rate * y[i])

            # =========================================
            if quit:
                break


    def batch_train(self, x, y, learning_rate):
        num_data = x.shape[0]
        """
        Batch Training of perceptron 
        Perceptron Batch Training updates weights all at once for every data (not everytime)
        Training ends when there is no misclassified data.
        See Lecture Notes 'W09 Neural network basics'
        Again, Do not implement funtionalities such as shuffling data or sth. 
    
        [Inputs]
            x : input for perceptron. Numpy array of (N, D)
            y : label of data x. Numpy array of (N, )
            learning_rate : learning rate.
    
        [Outputs]
            None
        """
        while True:
            # gradients of W & b
            dW = np.zeros_like(self.W)
            db = np.zeros_like(self.b)

            # Repeat until quit condition is satisfied.
            quit = True
            for i in range(num_data):
            # =============== EDIT HERE ===============

                # Finding a set of incorrect samples
                y_expected = self.forward(x[i])
                if y_expected != y[i]:
                    quit = False
                    # When it finds incorrect sample, add its derivative to the gradients
                    for j in range(x.shape[1]):
                        dW[j] += (y[i] * x[i][j])
                    db += y[i]

            # Update at once
            if quit is False:
                for j in range(x.shape[1]):
                    self.W[j] += learning_rate * dW[j]
                self.b += learning_rate * db

            # =========================================
            if quit:
                break

# ======================================================================



# ====================== MultiLayer Perceptron =========================

def softmax(z):
    # Numerically stable softmax. Already implemented.
    z = z - np.max(z, axis=1, keepdims=True)
    _exp = np.exp(z)
    _sum = np.sum(_exp, axis=1, keepdims=True)
    sm = _exp / _sum
    return sm

class ReLU:
    """
    ReLU Function. ReLU(x) = max(0, x)
    Implement forward & backward path of ReLU.
    """

    def __init__(self):
        # 1 (True) if ReLU input < 0
        self.zero_mask = None

    def forward(self, z):
        """
        ReLU Forward.
        ReLU(x) = max(0, x)

        z --> (ReLU) --> out

        [Inputs]
            z : ReLU input in any shape.

        [Outputs]
            out : ReLU(z).
        """
        out = None
        # =============== EDIT HERE ===============

        out = np.zeros_like(z)
        self.zero_mask = np.zeros_like(z)
        dim = len(z.shape)

        if dim == 1:
            for i in range(0, z.shape[0]):
                if z[i] < 0:
                    self.zero_mask[i] = 1
                    out[i] = 0
                else:
                    out[i] = z[i]
        elif dim == 2:
            for i in range(0, z.shape[0]):
                for j in range(0, z.shape[1]):
                    if z[i][j] < 0:
                        self.zero_mask[i][j] = 1
                        out[i][j] = 0
                    else:
                        out[i][j] = z[i][j]

        # =========================================
        return out

    def backward(self, d_prev):
        """
        ReLU Backward.

        z --> (ReLU) --> out
        dz <-- (dReLU) <-- d_prev(dL/dout)

        [Inputs]
            d_prev : Gradients until now.
            d_prev = dL/dk, where k = ReLU(z).

        [Outputs]
            dz : Gradients w.r.t. ReLU input z.
        """
        dz = None
        # =============== EDIT HERE ===============

        dz = np.zeros_like(d_prev)
        dim = len(d_prev.shape)

        if dim == 1:
            for i in range(0, d_prev.shape[0]):
                if self.zero_mask[i] != 1:
                    dz[i] = d_prev[i]
        elif dim == 2:
            for i in range(0, d_prev.shape[0]):
                for j in range(0, d_prev.shape[1]):
                    if self.zero_mask[i][j] != 1:
                        dz[i][j] = d_prev[i][j]

        # =========================================
        return dz

class Sigmoid:
    """
    Sigmoid Function.
    Implement forward & backward path of Sigmoid.
    """
    def __init__(self):
        self.out = None

    def forward(self, z):
        """
        Sigmoid Forward.

        z --> (Sigmoid) --> self.out

        [Inputs]
            z : Sigmoid input in any shape.

        [Outputs]
            self.out : Sigmoid(z).
        """
        self.out = None
        # =============== EDIT HERE ===============

        sigmoid = np.zeros_like(z)
        dim = len(z.shape)

        if dim == 1:
            for i in range(0, z.shape[0]):
                sigmoid[i] = 1 / (1 + np.exp(-z[i]))
        elif dim == 2:
            for i in range(0, z.shape[0]):
                for j in range(0, z.shape[1]):
                    sigmoid[i][j] = 1 / (1 + np.exp(-z[i][j]))

        self.out = sigmoid

        # =========================================
        return self.out

    def backward(self, d_prev):
        """
        Sigmoid Backward.

        z --> (Sigmoid) --> self.out
        dz <-- (dSigmoid) <-- d_prev(dL/d self.out)

        [Inputs]
            d_prev : Gradients until now.

        [Outputs]
            dz : Gradients w.r.t. Sigmoid input z.
        """
        dz = None
        # =============== EDIT HERE ===============

        dz = np.zeros(d_prev.shape, float)

        dim = len(d_prev.shape)

        if dim == 1:
            for i in range(0, d_prev.shape[0]):
                if d_prev[i] != 0:
                    out = self.out[i]
                    dz[i] = out * (1 - out)
        elif dim == 2:
            for i in range(0, d_prev.shape[0]):
                for j in range(0, d_prev.shape[1]):
                    if d_prev[i][j] != 0:
                        out = self.out[i][j]
                        dz[i][j] = out * (1 - out)

        # =========================================
        return dz


"""
** Multilayer Perceptron **
[input -- (input layer) --> hidden1 -- (hidden layer) --> hidden -- (output layer) --> output]

You will implement input/hiddden/output layers.

TIP : Draw computational graph and compute gradients to code BEFOREHAND.
"""

class InputLayer:
    """
    Input Layer
    input -- (input layer) --> hidden

    Implement forward & backward path.
    """
    def __init__(self, num_features, num_hidden_1, activation):
        # Weights and bias
        self.W = np.random.rand(num_features, num_hidden_1)
        self.b = np.zeros(num_hidden_1)
        # Gradient of Weights and bias
        self.dW = None
        self.db = None
        # Forward input
        self.x = None
        # Activation function (Sigmoid or ReLU)
        self.act = activation()

    def forward(self, x):
        """
        Input layer forward
        - Feed forward
        - Apply activation function you implemented above.

        [Inputs]
           x : Input data (N, D)

        [Outputs]
            self.out : Output of input layer. Hidden. (N, H)
        """
        self.x = None
        self.out = None
        # =============== EDIT HERE ===============

        self.out = np.zeros((x.shape[0], self.W.shape[1]), float)

        self.x = x
        z = np.matmul(x, self.W) + self.b
        self.out = self.act.forward(z)

        # =========================================
        return self.out

    def backward(self, d_prev):
        """
        Input layer backward
        x and (W & b) --> z -- (activation) --> hidden
        dx and (dW & db) <-- dz <-- (activation) <-- hidden

        - Backward of activation
        - Gradients of W, b

        [Inputs]
            d_prev : Gradients until now.

        [Outputs]
            None
        """
        self.dW = None
        self.db = None
        # =============== EDIT HERE ===============

        dz = self.act.backward(d_prev)
        mul = np.matmul(dz, self.x)
        self.dW = np.transpose(mul)

        self.db = np.zeros(dz.shape[0])
        for i in range(0, dz.shape[0]):
            for j in range(0, dz.shape[1]):
                self.db[i] += dz[i][j]

        # =========================================

class SigmoidOutputLayer:
    def __init__(self, num_hidden_2, num_outputs):
        # Weights and bias
        self.W = np.random.rand(num_hidden_2, num_outputs)
        self.b = np.zeros(num_outputs)
        # Gradient of Weights and bias
        self.dW = None
        self.db = None
        # Input (x), label(y), prediction(y_hat)
        self.x = None
        self.y = None
        self.y_hat = None
        # Loss
        self.loss = None
        # Sigmoid function
        self.sigmoid = Sigmoid()

    def forward(self, x, y):
        """
        Sigmoid output layer forward
        - Make prediction
        - Calculate loss

        ## Already Implemented ##
        """
        self.y_hat = self.predict(x)
        self.y = y
        self.x = x

        self.loss = self.binary_ce_loss(self.y_hat, self.y)

        return self.loss

    def binary_ce_loss(self, y_hat, y):
        """
        Calcualte "Binary cross-entropy loss"
        Add 'eps' for stability inside log function.

        [Inputs]
            y_hat : Prediction
            y : Label

        [Outputs]
            loss value
        """
        eps = 1e-10
        bce_loss = None
        # =============== EDIT HERE ===============
        '''
        def binary_crossentropy(y, t):
            return -tf.reduce_mean(t * tf.log(y + 1e-7) - (1-t) * tf.log(1 - y + 1e-7))
        '''

        bce_loss = -np.mean(y * np.log(y_hat + eps) + (1-y) * np.log(1 - y_hat + eps))

        # =========================================
        return bce_loss

    def predict(self, x):
        """
        Make prediction in probability. (Not 0 or 1 label!!)

        [Inputs]
            x : input data

        [Outputs]
            y_hat : Prediction
        """
        y_hat = None
        # =============== EDIT HERE ===============
        z = np.matmul(x, self.W) + self.b
        y_hat = self.sigmoid.forward(z)
        # =========================================
        return y_hat

    def backward(self, d_prev=1):
        """
        Calculate gradients of input (x), W, b of this layer.
        Save self.dW, self.db to update later.

        x and (W & b) --> z -- (activation) --> y_hat --> Loss
        dx and (dW & db) <-- dz <-- (activation) <-- dy_hat <-- Loss

        [Inputs]
            d_prev : Gradients until here. (Always 1 since its output layer)

        [Outputs]
            dx : Gradients of output layer input x (Not MLP input x!)
        """
        batch_size = self.y.shape[0]
        dx = None
        # =============== EDIT HERE ===============

        '''
        dz = self.sigmoid.backward(d_prev)
        mul = np.matmul(dz, self.x)
        self.dW = np.transpose(mul)

        self.db = np.zeros(dz.shape[0])
        for i in range(0, dz.shape[0]):
            for j in range(0, dz.shape[1]):
                self.db[i] += dz[i][j]

        dx = np.matmul(self.W, dz)
        dx = np.transpose(dx)
        '''


        '''
        for i in range(0, outsize):
            dy_hat[i] = -np.mean(self.y[:][i]/self.y_hat[:][i] - (1-self.y[:][i])/(1-self.y_hat[:][i]))
            dz[i] = dy_hat[i] * (1-dy_hat[i])
        '''
        '''
        dy_hat = np.zeros(batch_size, float)
        dz = np.zeros_like(dy_hat)
        for i in range(0, batch_size):
            dy_hat[i] = -(self.y[i]/self.y_hat[i] - (1-self.y[i])/(1-self.y_hat[i]))
        for i in range(0, batch_size):
            if dy_hat[i] != 0:
                out = self.y_hat[i]
                dz[i] = out * (1 - out)
        dz = np.transpose(dz)
        mul = np.matmul(dz, self.x)
        self.dW = np.transpose(mul)

        self.db = [0]
        for i in range(0, dz.shape[0]):
                self.db[0] += dz[i]
        '''
        '''
        dy_hat = -np.mean(self.y/self.y_hat - (1-self.y)/(1-self.y_hat))
        dz = dy_hat * (1-dy_hat)
        print(dz)
        '''
        '''
        dz = np.zeros(d_prev.shape, float)

        dim = len(d_prev.shape)

        if dim == 1:
            for i in range(0, d_prev.shape[0]):
                if d_prev[i] != 0:
                    out = self.out[i]
                    dz[i] = out * (1 - out)
        '''

        # =========================================

        return dx


class HiddenLayer:
    def __init__(self, num_hidden_1, num_hidden_2):
        # Weights and bias
        self.W = np.random.rand(num_hidden_1, num_hidden_2)
        self.b = np.zeros(num_hidden_2)
        # Gradient of Weights and bias
        self.dW = None
        self.db = None
        # ReLU function
        self.act = ReLU()

    def forward(self, x):
        """
        Hidden layer forward
        - Feed forward
        - Apply activation function you implemented above.

        [Inputs]
           x : Input data (N, D)

        [Outputs]
            self.out : Output of input layer. Hidden. (N, H)
        """
        self.x = None
        self.out = None
        # =============== EDIT HERE ===============

        self.out = np.zeros((x.shape[0], self.W.shape[1]), float)

        self.x = x
        z = np.matmul(x, self.W) + self.b
        self.out = self.act.forward(z)

        # =========================================
        return self.out

    def backward(self, d_prev):
        """
        Hidden layer backward
        x and (W & b) --> z -- (activation) --> output
        dx and (dW & db) <-- dz <-- (activation) <-- output

        - Calculate gradients of input (x), W, b of this layer.
        - Save self.dW, self.db to update later.

        [Inputs]
            d_prev : Gradients until here.

        [Outputs]
            dx : Gradients of output layer input x (Not MLP input x!)
        """
        dx = None
        self.dW = None
        self.db = None
        # =============== EDIT HERE ===============

        dz = self.act.backward(d_prev)
        mul = np.matmul(dz, self.x)
        self.dW = np.transpose(mul)

        self.db = np.zeros(dz.shape[0])
        for i in range(0, dz.shape[0]):
            for j in range(0, dz.shape[1]):
                self.db[i] += dz[i][j]

        dx = np.matmul(self.W, dz)
        dx = np.transpose(dx)

        # =========================================
        return dx

class SoftmaxOutputLayer:
    def __init__(self, num_hidden_2, num_outputs):
        # Weights and bias
        self.W = np.random.rand(num_hidden_2, num_outputs)
        self.b = np.zeros(num_outputs)
        # Gradient of Weights and bias
        self.dW = None
        self.db = None
        # Input (x), label(y), prediction(y_hat)
        self.x = None
        self.y = None
        self.y_hat = None
        # Loss
        self.loss = None

    def forward(self, x, y):
        """
        Softmax output layer forward
        - Make prediction
        - Calculate loss

        ## Already Implemented ##
        """
        self.y_hat = self.predict(x)
        self.y = y
        self.x = x

        self.loss = self.ce_loss(self.y_hat, self.y)

        return self.loss

    def ce_loss(self, y_hat, y):
        """
        Calcualte "Cross-entropy loss"
        Add 'eps' for stability inside log function.

        [Inputs]
            y_hat : Prediction
            y : Label

        [Outputs]
            loss value
        """
        eps = 1e-10
        ce_loss = None
        # =============== EDIT HERE ===============

        ce_loss = -np.sum(y * np.log(y_hat + eps))

        # =========================================
        return ce_loss

    def predict(self, x):
        """
        Make prediction in probability. (Not 0, 1, 2 ... label!!)
        # Use softmax function above.

        [Inputs]
            x : input data

        [Outputs]
            y_hat : Prediction
        """
        y_hat = None
        # =============== EDIT HERE ===============

        z = np.matmul(x, self.W) + self.b
        z = z - np.max(z, axis=1, keepdims=True)
        _exp = np.exp(z)
        _sum = np.sum(_exp, axis=1, keepdims=True)
        sm = _exp / _sum
        y_hat = sm

        # =========================================
        return y_hat

    def backward(self, d_prev=1):
        """
        Calculate gradients of input (x), W, b of this layer.
        Save self.dW, self.db to update later.

        x and (W & b) --> z -- (activation) --> y_hat --> Loss
        dx and (dW & db) <-- dz <-- (activation) <-- dy_hat <-- Loss

        [Inputs]
            d_prev : Gradients until here. (Always 1 since its output layer)

        [Outputs]
            dx : Gradients of output layer input x (Not MLP input x!)
        """
        batch_size = self.y.shape[0]
        dx = None
        # =============== EDIT HERE ===============






        # =========================================
        return dx

# ======================================================================