### 목표 : 모델선택에 따른 차이 구현

# par(mfrow=c(2,2))
# result = c()

### 1. 데이터를 학습 데이터와 검증 데이터로 나누어 모델 구현(정규화 방법으로 구하였습니다.)
# 관측된 데이터
N = 10  # 관측값의 개수
x = sample(seq(-2,2, by=1/N), size=N, replace=F)
t = x^2 + sin(3*x) + rnorm(N, sd=0.1)       # 평균 0, 분산 0.1의 정규분포를 따르는 노이즈를 주었습니다.
plot(t~x, xlim=c(-4,4), ylim=c(-2, 6))      # 그래프를 그려 분포를 보여줍니다.


# 학습파트 - weight 결정
N_FOR_LEARNING = 7              # 학습에 사용할 데이터의 개수 
M = 5                           # 곡선 피팅 다항식의 차수
lambda = exp(1)^(-18)           # ln(lambda) = -18
t_learn = t[1:N_FOR_LEARNING]   # 1~{N_FOR_LEARNING}번째 관측 데이터입니다.

X = matrix(0, nrow=N_FOR_LEARNING, ncol=M+1) 
for(i in 1:N_FOR_LEARNING){
    for(j in 1:(M+1)){
        X[i,j] = x[i]^(j-1)
    }
}

Lambda = lambda * diag(M+1)   # 아래 행렬식을 미분하는데 활용하기 위하여 변형시켜줍니다.
weight_reg = solve(t(X) %*% X + Lambda, tol=1e-20) %*% t(X) %*% t_learn
y_reg = function(x){
    res = 0
    for(i in 1:(M+1)){
        res = res + weight_reg[i]*x^(i-1)
    }
    return(res)
}

lines(seq(-4,4, by=0.01), y_reg(seq(-4,4, by=0.01)), col='blue')  # 만들어진 모델을 시각화합니다.

# 검증파트
N_FOR_VERIFICATION = N-N_FOR_LEARNING           # 검증에 사용할 데이터의 개수
x_verif = x[(N_FOR_LEARNING+1):N]               # {N_FOR_LEARNING+1}~{N}번째 관측 데이터의 x 값입니다.
t_verif = t[(N_FOR_LEARNING+1):N]               # {N_FOR_LEARNING+1}~{N}번째 관측 데이터입니다.
e_verif = mean((t_verif - y_reg(x_verif))^2)    # 편차제곱평균을 구해줍니다.

# result = append(result, e_verif)
# mean(result)

lines(seq(-4,4, by=0.01), seq(-4,4, by=0.01)^2 + sin(3*seq(-4,4, by=0.01)), col='red')
paste("오차제곱합:", e_verif)

### 2. 교차검증법을 활용