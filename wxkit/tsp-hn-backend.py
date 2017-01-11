#!/usr/bin/python3
import numpy as np

def init(file_name):
    coords = np.genfromtxt(file_name, delimiter=',')
    z=np.array( [[complex(coords[i,0],coords[i,1]) for i in range(len(coords))]] )
    N = len(coords)
    
    W = abs(z.T - z) / z.std()
    
    return N, W, coords


def evaluate(V):
    row_loss = (V.T.dot(V))[~np.eye(N, dtype=bool)].sum()
                
    col_loss = (V.dot(V.T))[~np.eye(N, dtype=bool)].sum()
                
    num_loss = (V.sum() - (N+sigma))**2
    
    dst_loss = 0
    for x in range(N):
        for y in range(N):
            if x == y: continue
            for i in range(N):
                dst_loss += W[x, y] * V[x, i] * (V[y, (i+1)%N] + V[y, (i-1)%N])
                
    
    loss = A/2 * row_loss\
        + B/2 * col_loss\
        + C/2 * num_loss\
        + D/2 * dst_loss
    
    return loss #, row_loss, col_loss, num_loss, dst_loss
    
def validate(V):
    res = 0
    res += abs((V.T.dot(V))[~np.eye(N, dtype=bool)].sum())
    res += abs((V.dot(V.T))[~np.eye(N, dtype=bool)].sum())
    res += abs(round(V.sum()) - N)
    
    return res == 0
    
    
        
def external_iteration(V):

    def internal_iteration(V):
        for in_it in range(N**2):
            # Full update cycle, i.e. random neuron every time
            x = np.random.randint(N)
            i = np.random.randint(N)

            d_row_loss = V[x].sum() - V[x, i]
            d_col_loss = V[:, i].sum() - V[x, i]
            d_num_loss = V.sum() - (N + sigma)
            d_dst_loss = W[x, :].dot(V[:, (i+1)%N] + V[:, (i-1)%N])
            
            u = \
                - A*d_row_loss\
                - B*d_col_loss\
                - C*d_num_loss\
                - D*d_dst_loss

            V[x, i] = (1+np.tanh(u*alpha))/2.0
        return V
    for ex_it in range(5): 
        V = internal_iteration(V)
    return V
    
    
def main():
    global N
    global W
    
    global A
    global B
    global C
    global D
    
    global alpha
    global sigma
    
    file_name = 'TSP-coords.txt'    
    
    print ('Generating distance matrix...')
    N, W, coords = init(file_name)
    np.set_printoptions(precision=1)

    #W = np.ones_like(W) - np.eye(N)
    
    #print(W)
    #W = np.random.randn(N, N)
    W.flat[::N+1] = 0
    print(W)

    #b = np.random.random_integers(-10,10,size=(N,N))
    #W = (b + b.T)/2
    
    A = 100
    B = 100
    C = 50
    D = 9
    
    print ('Number of points:', N)
    
    print ('HYPERPARAMETHERS\n'+'='*20)
    print ('A', A)
    print ('B', B)
    print ('C', C)
    print ('D', D)
    
    
    alpha = 100
    sigma = 2
    
    print ('alpha', alpha)
    print ('sigma', sigma)
    
    
    V = np.random.rand(N,N)
    
    best_E = evaluate(V)
    best_V = V

    
    combo = 0
    for it in range(200):
        if combo == 5: # Converged to MET local minima
            break
        
        print('\rIteration:', it+1, end='   ') 
        
        V = external_iteration(V)
        E = evaluate(V)

        if E < best_E:
            best_E = E
            best_V = V
        elif E == best_E and validate(V):
            combo += 1
        else: combo = 0    
            
    print('\nFINISHED, final E = ', best_E)
    solution = coords[np.argmax(best_V, 1)]
    np.savetxt(X=solution, fname='HN-solution.txt', delimiter=', ', fmt='%d')
    if validate(best_V):
        print(best_V)
    else:
        print('INVALID SOLUTION!')
    
if __name__ == "__main__":
    main()

