3개 연속이면 하나씩이나 한칸떨어진 경우밖에 없지 않나?

즉 D[N]=D[N-1]+A[N] or D[N-2]+A[N]로 생각했다.

그러나 6개중 최대가 될수있는 경우를 고려하면 다음과 같은데 이 중 1256의 경우가 체크가 안된다.

1245 1246 1256 1346 1356 2356

즉 중간에 2칸이상을 초과하여 띈 경우도 있다는 것!

그렇다면 다시 차분히 생각해보자.

3개가 연속되면 안된다고하면 현재의 경우에서 선택지는 세개이다.
- 0개 연속 : 지금 위치를 마시지 않는경우
- 1개 연속 : 두개 전의 최대값 + 지금 마시는 양
- 2개 연속 : 세개 전의 최대값 + 하나전 마시는 양 + 현재 마시는 양
