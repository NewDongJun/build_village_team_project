# build_village_team_project

# 1.월드소
저희 10조는 축구장을 메인으로 그에 어울리는 건추물들로 마인크래프트 월드를 꾸몄습니다.
우선 축구장의 필드와 관중석, 선수들을 배치하였고 그 후 주변에 CAU 스포츠센터와 트로피 건축물을 세웠습니다.
그리고 하늘에는 열기구를 띄웠습니다.

# 2.기본함수 
//1.사각형을 만드는 함수
//블록, x좌표, y좌표, z좌표, x너비, y너비, z너비 를 받음
	void rectangle(BlockID block, int x, int y, int z, int xlen, int ylen, int zlen) {
		for (int i = 0; i < xlen; i++) {
			for (int j = 0; j < ylen; j++) {
				for (int k = 0; k < zlen; k++) {
					locateBlock(block, x + i, y + j, z + k);
				}
			}
		}
	}

//2. 기둥을 만드는 함수 
//x좌표 y좌표, z좌표 y의 너비를 받음
	void pillar(int x, int y, int z, int ylen) {
		BlockID iron = createBlock(BLOCK_IRON);
		for (int i = 0; i < ylen; i++) {
			locateBlock(iron, x + 1, y + i, z);
			locateBlock(iron, x - 1, y + i, z);
			locateBlock(iron, x, y + i, z + 1);
			locateBlock(iron, x, y + i, z - 1);
		}
	}

//3. 원을 만드는 함수
//블록 x좌표 y좌표 z좌표 반지름을 받음 
void circle(BlockID block, int x, int y, int z, int r) {
	
	double PI = 3.14159265358979323846;
	double radian = PI / 180;

	for (int i = 0; i < 360; i++) {
		double rx = r * cos(radian * i);
		double rz = r * sin(radian * i);
		locateBlock(block, x + rx, y, z + rz);
	}
}
//3-2. 원을 만드는 함수2
//블록 x좌표 y좌표 z좌표 반지름을 받음 
void circle_y(BlockID block, int x, int y, int z, int r) {

	double PI = 3.14159265358979323846;
	double radian = PI / 180;

	for (int i = 0; i < 360; i++) {
		double ry = r * cos(radian * i);
		double rz = r * sin(radian * i);
		locateBlock(block, x , y+ry, z + rz);
	}
}


//4. 선그리는 함수
//블록 x좌표 y좌표 z좌표 x너비 z너비를 받음
void line(BlockID block, int x, int y, int z, int xlen, int zlen) {
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < zlen; j++) {
			locateBlock(block, x + i, y, z + j);
		}
	}
}

//5. 0부터 n-1까지 개의 난수를 생성하는 함수
// n을 받음
int random(int n) {
	srand((unsigned)time(NULL));
	int rd = rand();

	return(rd % n);
}


//6. 의자함수N
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_N (StairsID stairs, int x, int y, int z, int xlen, int ylen) {
	
	//의자 생성 
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < ylen; j++)
		{
			//z좌표 감소하는 쪽이 북쪽이므로 z-j가 맞음
			installStairs(stairs, x + i, y + j, z -j, FACING_NORTH);

		}
	}

	//의자뒤의 빈부분 채워주는 함수
	WoodID wood = createWood(WOOD_DARK_OAK);   //의자 빈부분을 뭘로 채울지 결정
	for (int i = 0; i < xlen; i++) {
		for (int j = 1; j < ylen; j++)
		{
			int high = j;
			while (high >= 1) {
				//z좌표 감소하는 쪽이 북쪽이므로 z-j가 맞음
				locateBlock(wood, x + i, y + high - 1, z - j);
				high--;
			}
		}
	}
}

//7. 의자함수S
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_S (StairsID stairs, int x, int y, int z, int xlen, int ylen) {
	
	//의자 생성 
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < ylen; j++)
		{
			//z좌표 감소하는 쪽이 남쪽이므로 z+j
			installStairs(stairs, x + i, y + j, z + j, FACING_SOUTH);

		}	
	}
	
	//의자뒤의 빈부분 채워주는 함수
	WoodID wood = createWood(WOOD_DARK_OAK);   //의자 빈부분을 뭘로 채울지 결정
	for (int i = 0; i < xlen; i++) {
		for (int j = 1; j < ylen; j++)
		{
			int high = j;
			while (high >= 1) {
				//z좌표 감소하는 쪽이 북쪽이므로 z+j가 맞음
				locateBlock(wood, x + i, y + high - 1, z + j);
				high--;
			}
		}
	}

}

//8. 의자함수E
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_E (StairsID stair, int x, int y, int z, int zlen, int ylen) {

	//의자생성
	for (int i = 0; i < zlen; i++) {
		for (int j = 0; j < ylen; j++) {

			installStairs(stair, x + j, y + j, z + i, FACING_EAST);
		}
	}

	//의자뒤 빈부분 채워줌
	WoodID wood = createWood(WOOD_DARK_OAK);   //의자 빈부분을 뭘로 채울지 결정 
	for (int i = 0; i < zlen; i++) {
		for (int j = 1; j < ylen; j++) {

			int high = j;
			while (high >= 1) {
				locateBlock(wood, x + j, y + high - 1, z + i);
				high--;
			}

		}
	}
}

//9. 의자함수W
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_W(StairsID stair, int x, int y, int z, int zlen, int ylen) {

	//의자생성
	for (int i = 0; i < zlen; i++) {
		for (int j = 0; j < ylen; j++) {

			installStairs(stair, x - j, y + j, z + i, FACING_WEST);
		}
	}

	//의자뒤 빈부분 채워줌
	WoodID wood = createWood(WOOD_DARK_OAK);   //의자 빈부분을 뭘로 채울지 결정 
	for (int i = 0; i < zlen; i++) {
		for (int j = 1; j < ylen; j++) {

			int high = j;
			while (high >= 1) {
				locateBlock(wood, x - j, y + high - 1, z + i);
				high--;
			}

		}
	}
}

//10. 딜레이 함수
//for문 반복횟수를 받는다.
void delay(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {

			}
		}
	}
}

//11. 구를 만드는 함수
//block, x좌표, y좌표, z좌표, 구의 반지름을 받음
void circle2(BlockID block, int x, int y, int z, int r) {

	double PI = 3.14159265358979323846;
	double radian = PI / 180;

	for (int i = 0; i < 360; i++) {
		double rx = r * cos(radian * i);
		double rz = r * sin(radian * i);

		//원을 만들면서 z축을 기준으로 회전시킴
		for (int j = 0; j < 360; j++) {
			double rx2 = rx * cos(radian * j);
			double ry2 = rx * sin(radian * j);
			locateBlock(block, x + rx2, y + ry2, z + rz);
		}
	}

}

//12.축구공 함수
	
void soccerball(int x, int y, int z, int r) {
		
		WoolID a1 = createWool(BlockColor(COLOR_BLACK));
		WoolID a2 = createWool(BlockColor(COLOR_WHITE));
		double PI = 3.14159265358979323846;
		double radian = PI / 180;

		for (int i = 1; i < 360; i++) {
			double rx = r * cos(radian * i);
			double rz = r * sin(radian * i);

			//원을 만들면서 z축을 기준으로 회전시킴
			for (int j = 1; j < 360; j = j++) {
				double rx2 = rx * cos(radian * j);
				double ry2 = rx * sin(radian * j);
				locateBlock(a2, x + rx2, y + ry2, z + rz);
			}
		}
		for (int i = 0; i < 360; i = i + 4) {
			double rx = r * cos(radian * i);
			double rz = r * sin(radian * i);

			//원을 만들면서 z축을 기준으로 회전시킴
			for (int j = 0; j < 360; j = j + 4) {
				double rx2 = rx * cos(radian * j);
				double ry2 = rx * sin(radian * j);
				locateBlock(a1, x + rx2, y + ry2, z + rz);
			}
		}
	}

# 3.기본기능을 이용해서 만든 함수
woo.cpp

chair_woo(); 관객석 함수/의자 기본 함수를 이용하여 운동장 주변을 관객석으로 둘러 싸았다.

mainground(); 운동장 함수/ 사각형 함수와 선 함수 그리고 원을 그리는 함수를 이용하여 운동장을 만들고 흰색 선을 그려넣었음.

sportcenter(); 스포츠 센터 건물 함수/ 사각형 함수를 이용하여 건물을 짓고 원함수를 이용하여 건물 위쪽에 조형물을 설치함. for문을 이용하여 CAUSPORTS글씨를 만들었음.
위의 함수는 woo(); 함수에서 호출하도록 woo(); 함수를 만듬

dong.cpp

void plant_flower(int x, int y, int z, int xlen, int zlen)
랜덤으로 꽃을 심는함수 원하는 좌표에 원하는 직사각형 크기로 꽃을 심을 수 있다.
주어진 값안에서 랜덤으로 수를 반환하는 기본함수를 사용해서 심어지는 꽃이 무작위로 변환되게 만들었다.

void trophy(int x, int y, int z)
트로피 조형물을 만드는 함수
원을 그리는 기본함수를 사용해서 만들었다.

min.cpp

soccerpillar(BlockID block, int x, int y, int z, int xlen, int ylen, int zlen);
축구골대함수/x,y,z좌표를 입력받고 축구골대를 원하는 크기를 정하여가로 세로 높이 길이를 입력하면 축구골대가 만들어진다.
netR(BlockID block, int x, int y, int z, int xlen, int ylen, int zlen);
netL(BlockID block, int x, int y, int z, int xlen, int ylen, int zlen);
 netR함수는 경기장 오른쪽의 골대의 그물, netL함수는 경기작 왼편의 골대 그물이다. soccerpillar함수에 입력한 값과 동일한 좌표와 길이를 입력받으면 그물이 만들어진다. 하지만 그물을 대체 찾기 어려워 모양이 이쁘지 않아서 비워두기로 했다. 
void pillar1(int x, int y, int z, int ylen); 단순 기둥만드는 함수이다. 
void airballoon(int rectc, int x, int y, int z, int xlen, int ylen, int zlen);
기본함수 void circle2 와 void rectangle 함수와 void pillar1 함수를 사용
Circle2함수를 사용하여 열기구의 원부분을 만들었고 rectangle함수를 사용하여 열기구 밑부분을 만들었다. 그리고 pillar1함수를 사용하여 원부분과 밑부분을 연결해주는 부위를 만들었다.

nyeng.cpp

score(int sx, int sy, int sz) 함수에서는 입력한 숫자에 따라 마인크래프트 세상에서 디지털식 숫자표기법으로 입력받은 숫자를 표기하는 함수이다.
if( 0~9)까지를 모두 정의해주어 작동하게 만들었다.
scoreboard()은 기본함수 rectangle()을 활용하여 전광판의 틀을 만드는 함수이다.
fence()은 기본함수 line()함수를 활용하여 경기장과 관중석 사이에 펜스를 두르는 함수이다.
person1(int x, int y, int z), person2(int x, int y, int z) 함수는 사람과 유사한 모양으로 블록을 배치하여 사람을 만들어낸 함수이다.
nyeng();함수는 위의 함수들을 모두 묶어 편하게 실행해주기 위해 만들어낸 함수이다.

# 4.유튜브 동영상 
유투브 영상 링크 : https://www.youtube.com/channel/UCEt9hdve8MtbX9oGdPxpwgA?view_as=subscriber
