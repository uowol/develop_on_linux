### '프로그래머를 위한 선형대수' 교재에 나와있는 예제를 구현한 코드입니다.

### 이 예제는 예외가 발생할 가능성이 존재합니다. (분모 자리에 0이 들어가는 오류)

lu_decomp = function(mat){  
    rows = nrow(mat)
    cols = ncol(mat)
    if(rows < cols){
        s = rows
    } else { s = cols }
    for(k in 1:(s-1)){  # 1행 1열부터 s-1행 s-1열까지 차례차례 분해합니다.
        x = 1/mat[k,k] 
        for(i in (k+1):rows){   # k행 k열을 1로 맞추기 위해 모든 행을 적절하게 나누어줍니다(k행 제외).
            mat[i, k] = mat[i, k] * x   # 나누기보다 곱셈이 빠르므로 곱셈을 사용해줍니다.
        }
        for(i in (k+1):rows){   # 현재 행과 열은 분해된 열로 남겨둡니다.
            for(j in (k+1):cols){
                mat[i,j] = mat[i,j] - mat[i,k]*mat[k,j]
            }
        }
    }
    return(mat)
}

sol = function(a, y){   # Ax = y 연립방정식의 해 x를 구해주는 함수입니다.
    lu = lu_decomp(a)        # A를 LU로 분해해줍니다.
    x = sol_lu(lu, y)
    return(x)
}

sol_lu = function(lu, y){
    n = length(y)
    z = sol_l(lu, y, n) # Lz = y를 풀어 해 z를 구해줍니다.
    x = sol_u(lu, z, n) # Ux = z를 풀어 해 x를 구해줍니다.
    return(x)
}

sol_l = function(lu, y, n){ # Lz=y, z값을 y에 덮어씌워 계산합니다. n은 y의 크기
    for(i in 1:n){
        # L은 하삼각행렬
        # z[i] = y[i] - L[i,1]*z[1] - L[i,2]*z[2] - ... - L[i,i-1]*z[i-1]
        if(i == 1) next # z[1] = y[1]
        for(j in 1:(i-1)){
            y[i] = y[i] - lu[i,j]*y[j]  # 실질적으로는 y[i] - L[i,j]*z[j]
        }
    }
    return(y)
}

sol_u = function(lu, z, n){ # Ux=z, x값을 z에 덮어씌워 계산합니다. n은 z의 크기
    for(i in n:1){
        # U는 상삼각행렬
        # x[i] = (z[i] - U[i,n]*z[n] - ... - U[i,i+1]*z[i+1])/U[i,i]
        if(i < n)   # x[n] = z[n] / U[n,n]
            for(j in n:(i+1)){
                z[i] = z[i] - lu[i,j]*z[j]  # 실질적으로는 z[i] - U[i,j]*z[j]
            }
        z[i] = z[i] / lu[i,i]
    }
    return(z)
}

### 활용

lu_decomp(matrix(c(2,6,4,5,7,9), byrow=T, nrow=2))
#      [,1] [,2] [,3]   
# [1,]  2.0    6    4       u   u   u
# [2,]  2.5   -8   -1       l   u   u   꼴

a = matrix(c(3,2,5,7), nrow=2, byrow=T)
y = c(6, 13)
sol(a, y)

l = matrix(nrow=2, c(1, 1.666667, 0, 1))
u = matrix(nrow=2, c(3, 0, 2, 3.666667))
lu = lu_decomp(a)
z = sol_l(lu, y, 2)
x = sol_u(lu, z, 2)
l%*%u%*%x   # c(6,13)

a%*%x       # c(6,13)
