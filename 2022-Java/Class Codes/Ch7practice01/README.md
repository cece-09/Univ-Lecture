## 실습 예제

1. 점의 위치를 나타내는 클래스 `Point` 가 다음과 같다.

```
class Point {
    int xPos, yPos;
    public Point(int x, int y) { ... }
    public void showPointInfo() { ... }
}
```
2. 위 `Point` 클래스를 완성하고 이 클래스를 이용하는 `Circle` class도 만들어 보자. `Circle` 클래스의 사용법은 아래와 같다. 원의 정보에는 현재 위치와 넓이, 둘레길이가 포함된다.
```
Circle c = new Circle(2, 2, 4.2) //좌표가 2,2 이고 반지름이 4.2인 원 생성
c.showCircleInfo();
```

정보은닉과 캡슐화를 지키는 방향으로 class 작성