### 목표 : 다항식 곡선 피팅

N = 10  # 관측값의 개수
M = 9   # 곡선 피팅 다항식의 차수

# 관측값을 랜덤하게 생성해줍니다.
x = sample(seq(0,1, by=1/N), size=N, replace=F)
t = sin(2*x*pi) + rnorm(N, sd=0.1)      # 평균 0, 분산 0.1의 정규분포를 따르는 노이즈를 주었습니다.
plot(t~x, xlim=c(0,1), ylim=c(-2, 2))   # 그래프를 그려 분포를 보여줍니다.

# N개의 학습데이터를 포함한 (w의)계수행렬을 만들어줍니다.
X = matrix(0, nrow=N, ncol=M+1) 
for(i in 1:N){
    for(j in 1:(M+1)){
        X[i,j] = x[i]^(j-1)
    }
}
# 역함수 계산 시, 허용 오차를 넓게 주지 않으면 오류가 발생할 수 있습니다.
weight = solve(t(X) %*% X, tol=1e-17) %*% t(X) %*% t    # 최소값을 얻을 수 있는 극소점 w를 구해줍니다.
y = function(x){
    res = 0
    for(i in 1:(M+1)){
        res = res + weight[i]*x^(i-1)
    }
    return(res)
}

lines(seq(0,1, by=0.01), y(seq(0,1, by=0.01)))
lines(seq(0,1, by=0.01), sin(2*pi*seq(0,1, by=0.01)), col='red')    # 일반화가 잘 되었는지 관측 모델과 비교해봅니다.
