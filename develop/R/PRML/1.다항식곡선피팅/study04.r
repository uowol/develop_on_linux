### 목표 : 베이지안 곡선피팅 2 - 주변화

N = 20  # 관측값의 개수
M = 5   # 곡선 피팅 다항식의 차수

beta = 11.1     # 관측값의 정밀도, 관측값이 평균이 y(x,w) 분산이 beta^(-1)의 정규분포를 따른다고 가정합니다.
alpha = 0.005   # 계수의 정밀도, 계수가 평균이 0 분산이 alpha^(-1)의 정규분포를 따른다고 가정합니다.

# 관측값을 랜덤하게 생성해줍니다.
x = sample(seq(0,1, by=1/N), size=N, replace=F)
t = sin(2*x*pi) + rnorm(N, sd=0.1)      # 평균 0, 분산 0.1의 정규분포를 따르는 노이즈를 주었습니다.
plot(t~x, xlim=c(0,1), ylim=c(-2, 2))   # 그래프를 그려 분포를 보여줍니다.

# w의 계수 벡터를 리턴해줍니다.
f = function(k){
    res = c()
    for(i in 0:M){
        res = append(res, k^i)
    }
    return(res)
}

S_inv = function(){
    f_sum_matrix = matrix(0, nrow=(M+1), ncol=(M+1))
    for(n in 1:N){
        f_sum_matrix = f_sum_matrix + f(x[n])%*%t(f(x[n]))
    }
    return(alpha*diag(M+1) + beta*(f_sum_matrix))
}

# 베이지안 방법으로 구한 예측 분포의 기대값입니다. 이 값이 관측값에 대한 추정값이 됩니다.
m = function(k){
    f_sum_vector = rep(0, M+1)
    for(n in 1:N){
        f_sum_vector = f_sum_vector + t[n]*f(x[n])
    }
    res = beta*t(f(k)) %*% solve(S_inv()) %*% f_sum_vector
    return(res)
}

y = c()
for(k in seq(0,1, by=0.01)){
    y = append(y, m(k))
}
lines(seq(0,1, by=0.01), y, type='l', col='blue')
lines(seq(0,1, by=0.01), y-0.3, type='l', col='red', lty=3)
lines(seq(0,1, by=0.01), y+0.3, type='l', col='red', lty=3)
lines(seq(0,1, by=0.01), sin(2*pi*seq(0,1, by=0.01)), col='green')    # 일반화가 잘 되었는지 관측 모델과 비교해봅니다.
