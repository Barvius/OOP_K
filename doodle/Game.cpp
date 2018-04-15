#include "Game.h"


void Game::MoveRight() {
	_Person.MovePositionX(7);
	_Person.LookRight();
	if (_Person.GetPosition().x < 0) {
		//x = 400;
		_Person.SetPositionX(400);
	};
	if (_Person.GetPosition().x > 400) {
		//x = 0;
		_Person.SetPositionX(0);
	};
}

void Game::MoveLeft() {
	_Person.MovePositionX(-7);
	_Person.LookLeft();
	if (_Person.GetPosition().x < 0) {
		//x = 400;
		_Person.SetPositionX(400);
	};
	if (_Person.GetPosition().x > 400) {
		//x = 0;
		_Person.SetPositionX(0);
	};
}



int hh = 250;
float dxx = 0, dyy = 0;
bool aa;
int randXx = 0;
void Game::Calculate() {
	dyy += 0.2;
	_Person.SetPositionY(_Person.GetPosition().y - dyy);


	if (_Person.GetPosition().y > hh) {
		for (int i = 0; i < N; i++) {

			_Person.SetPositionY(hh);
			Platform[i]->MovePositionY(dyy);
			
			if (Platform[i]->GetPosition().y < 0) {
				do {
					aa = true;
					randXx = rand() % 400;
					if (randXx < 34) randXx = 35 + rand() % 50;
					if (randXx >(400 - 34)) randXx = (400 - 35) - rand() % 50;
					if ((randXx > Platform[i]->GetPosition().y + 34 && randXx < Platform[i]->GetPosition().y - 34)) {
						aa = false;
					}
					switch (_PA.Gen()) {
					case 1:
						Platform[i] = new PlatformBasic(Coord(randXx, 533), _Texture);
						break;
					case 2:
						Platform[i] = new PlatformToss(Coord(randXx, 533), _Texture);
						break;
					default:
						break;
					}
					//Platform[i]->SetPosition(Coord(randXx, 533));
					for (int j = 0; j < N; j++) {
						if (Platform[i]->GetPosition().x + 20 < Platform[j]->GetPosition().y) {
							Platform[i]->MovePositionY(20);
						}

					}

				} while (!aa);

				//Score++;
			}

		}
	}

	// насилуем пк, убрать
	for (int i = 0; i < N; i++) {
		int sizeD = 30;

		if ((_Person.GetPosition().x + sizeD >= Platform[i]->GetPosition().x - 34 &&
			_Person.GetPosition().x - sizeD <= Platform[i]->GetPosition().x + 34) &&
			(_Person.GetPosition().y >= Platform[i]->GetPosition().y - 7 &&
				_Person.GetPosition().y - sizeD <= Platform[i]->GetPosition().y + 7) &&
				(dyy > 0)) {
			if (typeid(*Platform[i]) == typeid(PlatformToss)) {
				dyy = -15;
				cout << "chooooock" << endl;
			}
			else {
				dyy = -8;
				cout << "chock" << endl;
			}


		}
		if (_Person.GetPosition().y < 0) {
			_Person.SetPositionY(300);
			cout << "fail" << endl;
		}
	}
}

void Game::Render() {
	for (size_t i = 0; i < N; i++) {
		Platform[i]->Draw();
	}
	_Person.Draw();
}

void Game::MoveY(int a) {

}

Game::Game(GLuint texture){
	_Texture = texture;
	Coord coords;
	coords.x = 200;
	coords.y = 100;
	_Person = Person(coords,_Texture);
	for (int i = 0; i<N; i++) {
		switch (_PA.Gen()){
		case 1:
			Platform[i] = new PlatformBasic(Coord(rand() % 400, rand() % 533), _Texture);
			break;
		case 2:
			Platform[i] = new PlatformToss(Coord(rand() % 400, rand() % 533), _Texture);
			break;
		default:
			break;
		}
		
	}
	Platform[0]->SetPosition(Coord(200,20));
}

Game::Game(){
}

Game::~Game()
{
}
