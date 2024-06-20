# 2140번: 지뢰찾기 - <img src="https://static.solved.ac/tier_small/12.svg" style="height:20px" /> Gold IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/2140)


<p>지뢰찾기는 N×N에서 이뤄지는 게임이다. 보드의 곳곳에는 몇 개의 지뢰가 숨겨져 있고, 지뢰가 없는 칸에는 그 칸과 인접(상하좌우 및 대각선)해 있는 8개의 칸들에 몇 개의 지뢰가 숨겨져 있는지에 대한 정보가 주어진다. 게이머는 게임을 진행하면서 보드의 칸을 하나씩 열게 된다. 만약 그 칸에 지뢰가 있다면 게임이 끝나고, 없는 경우에는 그 칸에 적혀있는 숫자, 즉 그 칸과 인접해 있는 8개의 칸들 중 몇 개의 칸에 지뢰가 있는지를 알 수 있게 된다.</p>

<p>이 문제는 보드의 테두리가 모두 열려있고, 그 외는 모두 닫혀있는 상태에서 시작한다. 예를 들어 다음과 같은 경우를 보자.</p>

<table class="table table-bordered" style="width:25%">
<tbody>
<tr>
<td style="width:5%">1</td>
<td style="width:5%">1</td>
<td style="width:5%">1</td>
<td style="width:5%">0</td>
<td style="width:5%">0</td>
</tr>
<tr>
<td>2</td>
<td>#</td>
<td>#</td>
<td>#</td>
<td>1</td>
</tr>
<tr>
<td>3</td>
<td>#</td>
<td>#</td>
<td>#</td>
<td>1</td>
</tr>
<tr>
<td>2</td>
<td>#</td>
<td>#</td>
<td>#</td>
<td>1</td>
</tr>
<tr>
<td>1</td>
<td>2</td>
<td>2</td>
<td>1</td>
<td>0</td>
</tr>
</tbody>
</table>

<p>#는 닫혀있는 칸을 나타낸다. 이러한 보드가 주어졌을 때, 닫혀있는 칸들 중 최대 몇 개의 칸에 지뢰가 묻혀있는지 알아내는 프로그램을 작성하시오. 위의 예와 같은 경우에는 다음과 같이 6개의 지뢰가 묻혀있을 수 있다.</p>

<table class="table table-bordered" style="width:25%">
<tbody>
<tr>
<td style="width:5%">1</td>
<td style="width:5%">1</td>
<td style="width:5%">1</td>
<td style="width:5%">0</td>
<td style="width:5%">0</td>
</tr>
<tr>
<td>2</td>
<td>*</td>
<td>&nbsp;</td>
<td>&nbsp;</td>
<td>1</td>
</tr>
<tr>
<td>3</td>
<td>*</td>
<td>*</td>
<td>*</td>
<td>1</td>
</tr>
<tr>
<td>2</td>
<td>*</td>
<td>*</td>
<td>&nbsp;</td>
<td>1</td>
</tr>
<tr>
<td>1</td>
<td>2</td>
<td>2</td>
<td>1</td>
<td>0</td>
</tr>
</tbody>
</table>



## 입력


<p>첫째 줄에 N(1≤N≤100)이 주어진다. 다음 N개의 줄에는 N개의 문자가 공백 없이 주어지는데, 이는 게임 보드를 의미한다.</p>



## 출력


<p>첫째 줄에 묻혀있을 수 있는 지뢰의 최대 개수를 출력한다.</p>



## 소스코드

[소스코드 보기](지뢰찾기.cpp)