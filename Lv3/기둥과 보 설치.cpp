#include <string>
#include <vector>

using namespace std;

class element
{
private :
	bool pillar;	//기둥
	bool beam;		//보
public :
	element()
	{
		this->pillar = false;
		this->beam = false;
	}
	element(bool pillar, bool beam)
	{
		this->pillar = pillar;
		this->beam = beam;
	}
	void setPillar(bool pillar) { this->pillar = pillar; }
	void setBeam(bool beam) { this->beam = beam; }
	bool getPillar() { return this->pillar; }
	bool getBeam() { return this->beam; }
};

class Structure
{
private :
	int n;
	vector<vector<element>> structure; 
private :
	bool canBuildPillar(int, int);
	bool canBuildBeam(int, int);
	bool canDestroyPillar(int, int);
	bool canDestroyBeam(int, int);
public :
	Structure(int n)
	{
		this->n = n;
		this->structure = vector<vector<element>>(n + 1, vector<element>(n + 1));
	}
	void BuildPillar(int, int);
	void BuildBeam(int, int);
	void DestroyPillar(int, int);
	void DestroyBeam(int, int);
	vector<vector<int>> getInfo();
};
bool Structure::canBuildPillar(int x, int y)
{
	//바닥에 기둥을 설치한다면 설치를 허락
	if (y == 0)
	{
		return true;
	}

	if (x == 0)
	{
		//기둥을 설치하는 곳에 보가 설치되어 있거나 
		//아래쪽에 기둥이 있으면 설치 허락
		if (this->structure[x][y].getBeam() || 
			this->structure[x][y - 1].getPillar())
		{
			return true;
		}
	}
	else if (x == this->n)
	{
		//기둥을 설치하는 위치의 왼쪽에 보가 설치되어 있거나 
		//아래쪽에 기둥이 있으면 설치 허락
		if (this->structure[x - 1][y].getBeam() ||
			this->structure[x][y - 1].getPillar())
		{
			return true;
		}
	}
	else if (0 < x && x < this->n)
	{
		//기둥을 설치하는 곳에 보가 설치되어 있거나
		//기둥을 설치하는 위치의 왼쪽에 보가 설치되어 있거나 
		//아래쪽에 기둥이 있으면 설치 허락
		if (this->structure[x][y].getBeam() == true ||
			this->structure[x - 1][y].getBeam() == true ||
			this->structure[x][y - 1].getPillar() == true)
		{
			return true;
		}
	}

	return false;
}
bool Structure::canBuildBeam(int x, int y)
{

	//보를 설치하는 위치의 아래에 기둥이 있거나
	//보를 설치하는 곳의 오른쪽 아래에 기둥이 있다면 설치 허락
	if (this->structure[x][y - 1].getPillar() ||
		this->structure[x + 1][y - 1].getPillar())
	{
		return true;
	}

	//보를 설치하는 위치의 양 끝선에 기둥이 없고
	//연결된 보가 없을 경우 설치를 불허
	if (x == 0 || x == this->n - 1)
	{
		return false;
	}

	//보를 설치하는 위치의 양 끝선에 보가 존재한다면 설치를 허락
	if (0 < x && x < this->n - 1)
	{
		if (this->structure[x - 1][y].getBeam() && this->structure[x + 1][y].getBeam())
		{
			return true;
		}
	}

	return false;
}
bool Structure::canDestroyPillar(int x, int y)
{
	//원래 아무것도 없었다면 return false;
	if (this->structure[x][y].getPillar() == false)
	{
		return false;
	}

	//최상층에 있는 기둥을 삭제한다면(위의 기둥을 신경쓰지 않아도 된다)
	if (y == this->n - 1)
	{
		//왼쪽 끝의 기둥을 삭제한다면
		if (x == 0)
		{
			//위에 보의 왼쪽이 설치되어 있는 상황이라면
			if (this->structure[x][y + 1].getBeam() == true)
			{
				//위에 보의 오른쪽 아래에 기둥이 있다면 삭제 허가
				if (this->structure[x + 1][y].getPillar() == true)
				{
					return true;
				}
				
				return false;
			}

			return true;
		}
		//오른쪽 끝의 기둥을 삭제한다면
		else if (x == n)
		{
			//위쪽에 보의 오른쪽이 설치되어 있는 상황이라면
			if (this->structure[x - 1][y + 1].getBeam() == true)
			{
				//위에 보의 왼쪽 아래에 기둥이 있다면 삭제 허가
				if (this->structure[x - 1][y].getPillar() == true)
				{
					return true;
				}
				
				return false;
			}

			return true;
		}
		//나머지의 경우
		else if (0 < x && x < n)
		{
			//위쪽에 두개가 겹쳐있는 상황이라면
			if (this->structure[x - 1][y + 1].getBeam() == true &&
				this->structure[x][y + 1].getBeam() == true)
			{
				if (x == 1)
				{
					if (this->structure[x - 1][y].getPillar() == true &&
						(
							this->structure[x + 1][y + 1].getBeam() == true ||
							this->structure[x + 1][y].getPillar() == true)
						)
					{
						return true;
					}

					return false;
				}
				else if (x == this->n - 1)
				{
					if (this->structure[x + 1][y].getPillar() == true &&
						(
							this->structure[x - 2][y + 1].getBeam() == true ||
							this->structure[x - 1][y].getPillar() == true)
						)
					{
						return true;
					}

					return false;
				}
				else
				{
					if ((this->structure[x - 2][y + 1].getBeam() == true ||
						this->structure[x - 1][y].getPillar() == true)
						&&
						(this->structure[x + 1][y + 1].getBeam() == true ||
							this->structure[x + 1][y].getPillar() == true))
					{
						return true;
					}

					return false;
				}
			}
			//위쪽에 보의 오른쪽이 설치되어 있는 상황이라면
			else if (this->structure[x - 1][y + 1].getBeam() == true)
			{
				//위에 보의 왼쪽 아래에 기둥이 있다면 삭제 허가
				if (this->structure[x - 1][y].getPillar() == true)
				{
					return true;
				}

				return false;
			}
			//위쪽에 보의 왼쪽이 설치되어 있는 상황이라면
			else if (this->structure[x][y + 1].getBeam() == true)
			{
				//위에 보의 오른쪽 아래에 기둥이 있다면 삭제 허가
				if (this->structure[x + 1][y].getPillar() == true)
				{
					return true;
				}

				return false;
			}

			return true;
		}
	}
	//나머지 경우
	else
	{
		//왼쪽 끝의 기둥을 삭제한다면
		if (x == 0)
		{
			//위에 기둥이 설치되어 있다면
			if (this->structure[x][y + 1].getPillar() == true)
			{
				if (this->structure[x][y + 1].getBeam() == true)
				{
					//위에 보의 오른쪽 아래에 기둥이 있다면 삭제 허가
					if (this->structure[x + 1][y].getPillar() == true)
					{
						return true;
					}

					return false;
				}

				return false;
			}
			//위에 기둥이 없다면
			else
			{
				//위에 보의 왼쪽이 설치되어 있는 상황이라면
				if (this->structure[x][y + 1].getBeam() == true)
				{
					//위에 보의 오른쪽 아래에 기둥이 있다면 삭제 허가
					if (this->structure[x + 1][y].getPillar() == true)
					{
						return true;
					}

					return false;
				}

				return true;
			}
		}
		//오른쪽 끝의 기둥을 삭제한다면
		else if (x == n)
		{
			//위에 기둥이 설치되어 있다면
			if (this->structure[x][y + 1].getPillar() == true)
			{
				if (this->structure[x - 1][y + 1].getBeam() == true)
				{
					if (this->structure[x - 1][y].getPillar() == true)
					{
						return true;
					}

					return false;
				}

				return false;
			}
			//위에 기둥이 없다면
			else
			{
				//위에 보의 왼쪽이 설치되어 있는 상황이라면
				if (this->structure[x - 1][y + 1].getBeam() == true)
				{
					//위에 보의 오른쪽 아래에 기둥이 있다면 삭제 허가
					if (this->structure[x - 1][y].getPillar() == true)
					{
						return true;
					}

					return false;
				}

				return true;
			}
		}
		//나머지의 경우
		else 
		{
			//위에 기둥이 설치되어 있다면
			if (this->structure[x][y + 1].getPillar() == true)
			{
				//기둥위에 보가 2개설치 되어 있다면
				if (this->structure[x - 1][y + 1].getBeam() == true &&
					this->structure[x][y + 1].getBeam() == true)
				{
					if (x == 1)
					{
						if (this->structure[x - 1][y].getPillar() == true &&
							(this->structure[x + 1][y].getPillar() == true ||
								this->structure[x + 1][y + 1].getBeam() == true))
						{
							return true;
						}
						return false;
					}
					else if (x == this->n - 1)
					{
						if (this->structure[x + 1][y].getPillar() == true &&
							(this->structure[x - 1][y].getPillar() == true ||
								this->structure[x - 2][y + 1].getBeam() == true))
						{
							return true;
						}

						return false;
					}
					else
					{
						if ((this->structure[x + 1][y].getPillar() == true ||
							this->structure[x + 1][y + 1].getBeam() == true) &&
							(this->structure[x - 1][y].getPillar() == true ||
								this->structure[x - 2][y + 1].getBeam() == true))
						{
							return true;
						}

						return false;
					}
				}
				//위쪽의 보의 오른쪽이 설치되어 있는 상황이라면
				else if (this->structure[x - 1][y + 1].getBeam() == true)
				{
					if (this->structure[x - 1][y].getPillar() == true)
					{
						return true;
					}

					return false;
				}
				//위쪽의 보의 왼쪽이 설치되어 있는 상황이라면
				else if (this->structure[x][y + 1].getBeam() == true)
				{
					if (this->structure[x + 1][y].getPillar() == true)
					{
						return true;
					}

					return false;
				}

				return false;
			}
			//위에 기둥이 없다면
			else
			{
				//기둥위에 보가 2개설치 되어 있다면
				if (this->structure[x - 1][y + 1].getBeam() == true &&
					this->structure[x][y + 1].getBeam() == true)
				{
					if (x == 1)
					{
						if (this->structure[x - 1][y].getPillar() == true &&
							(this->structure[x + 1][y].getPillar() == true ||
								this->structure[x + 1][y + 1].getBeam() == true))
						{
							return true;
						}
						return false;
					}
					else if (x == this->n - 1)
					{
						if (this->structure[x + 1][y].getPillar() == true &&
							(this->structure[x - 1][y].getPillar() == true ||
								this->structure[x - 2][y + 1].getBeam() == true))
						{
							return true;
						}

						return false;
					}
					else
					{
						if ((this->structure[x + 1][y].getPillar() == true ||
							this->structure[x + 1][y + 1].getBeam() == true) &&
							(this->structure[x - 1][y].getPillar() == true ||
								this->structure[x - 2][y + 1].getBeam() == true))
						{
							return true;
						}

						return false;
					}
				}
				//위쪽의 보의 오른쪽이 설치되어 있는 상황이라면
				else if (this->structure[x - 1][y + 1].getBeam() == true)
				{
					if (this->structure[x - 1][y].getPillar() == true)
					{
						return true;
					}

					return false;
				}
				//위쪽의 보의 왼쪽이 설치되어 있는 상황이라면
				else if (this->structure[x][y + 1].getBeam() == true)
				{
					if (this->structure[x + 1][y].getPillar() == true)
					{
						return true;
					}

					return false;
				}

				return true;
			}
		}
	}
}
bool Structure::canDestroyBeam(int x, int y)
{
	//원래 아무것도 없었다면 return false;
	if (this->structure[x][y].getBeam() == false)
	{
		return false;
	}

	//현재 위치의 보를 삭제한다
	this->structure[x][y].setBeam(false);
	bool leftbeam, rightbeam, toppillar, toprightpillar;

	//삭제한 상태에서 관련된 보와 기둥이 설치가 가능한지 확인한다
	//코드 자체를 확인할 필요가 있다.
	if (y == this->n)
	{
		if (x == 0)
		{
			rightbeam = this->structure[x + 1][y].getBeam();

			//오른쪽에 보가 있다면
			if (rightbeam)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildBeam(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}

			this->structure[x][y].setBeam(true);
			return true;
		}
		else if (x == this->n - 1)
		{
			leftbeam = this->structure[x - 1][y].getBeam();

			//오른쪽에 보가 있다면
			if (leftbeam)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildBeam(x - 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}

			this->structure[x][y].setBeam(true);
			return true;
		}
		else
		{
			rightbeam = this->structure[x + 1][y].getBeam();
			leftbeam = this->structure[x - 1][y].getBeam();

			if (rightbeam && leftbeam)
			{
				if (this->canBuildBeam(x - 1, y) && this->canBuildBeam(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (rightbeam)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildBeam(x - 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (leftbeam)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildBeam(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}

			this->structure[x][y].setBeam(true);
			return true;
		}
	}
	else
	{
		if (x == 0)
		{
			rightbeam = this->structure[x + 1][y].getBeam();
			toppillar = this->structure[x][y].getPillar();
			toprightpillar = this->structure[x + 1][y].getPillar();
			
			if (rightbeam && toppillar && toprightpillar)
			{
				if (this->canBuildBeam(x + 1, y) && 
					this->canBuildPillar(x, y) && 
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (rightbeam && toppillar)
			{
				if (this->canBuildBeam(x + 1, y) &&
					this->canBuildPillar(x, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (rightbeam && toprightpillar)
			{
				if (this->canBuildBeam(x + 1, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (toppillar && toprightpillar)
			{
				if (this->canBuildPillar(x, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (rightbeam)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildBeam(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (toppillar)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildPillar(x, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (toprightpillar)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}

			this->structure[x][y].setBeam(true);
			return true;
		}
		else if (x == this->n - 1)
		{
			leftbeam = this->structure[x - 1][y].getBeam();
			toppillar = this->structure[x][y].getPillar();
			toprightpillar = this->structure[x + 1][y].getPillar();

			if (leftbeam && toppillar && toprightpillar)
			{
				if (this->canBuildBeam(x - 1, y) &&
					this->canBuildPillar(x, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (leftbeam && toppillar)
			{
				if (this->canBuildBeam(x - 1, y) &&
					this->canBuildPillar(x, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (leftbeam && toprightpillar)
			{
				if (this->canBuildBeam(x - 1, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (toppillar && toprightpillar)
			{
				if (this->canBuildPillar(x, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (leftbeam)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildBeam(x - 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (toppillar)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildPillar(x, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (toprightpillar)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}

			this->structure[x][y].setBeam(true);
			return true;
		}
		else
		{
			rightbeam = this->structure[x + 1][y].getBeam();
			leftbeam = this->structure[x - 1][y].getBeam();
			toppillar = this->structure[x][y].getPillar();
			toprightpillar = this->structure[x + 1][y].getPillar();

			if (leftbeam && rightbeam && toppillar && toprightpillar)
			{
				if (this->canBuildBeam(x - 1, y) &&
					this->canBuildBeam(x + 1, y) &&
					this->canBuildPillar(x, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (leftbeam && rightbeam && toppillar)
			{
				if (this->canBuildBeam(x - 1, y) &&
					this->canBuildBeam(x + 1, y) &&
					this->canBuildPillar(x, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (leftbeam && rightbeam && toprightpillar)
			{
				if (this->canBuildBeam(x - 1, y) &&
					this->canBuildBeam(x + 1, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (leftbeam && toppillar && toprightpillar)
			{
				if (this->canBuildBeam(x - 1, y) &&
					this->canBuildPillar(x, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (rightbeam && toppillar && toprightpillar)
			{
				if (this->canBuildBeam(x + 1, y) &&
					this->canBuildPillar(x, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (leftbeam && rightbeam)
			{
				if (this->canBuildBeam(x - 1, y) &&
					this->canBuildBeam(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (leftbeam && toppillar)
			{
				if (this->canBuildBeam(x - 1, y) &&
					this->canBuildPillar(x, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (leftbeam && toprightpillar)
			{
				if (this->canBuildBeam(x - 1, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (rightbeam && toppillar)
			{
				if (this->canBuildBeam(x + 1, y) &&
					this->canBuildPillar(x, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (rightbeam && toprightpillar)
			{
				if (this->canBuildBeam(x + 1, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (toppillar && toprightpillar)
			{
				if (this->canBuildPillar(x, y) &&
					this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (leftbeam)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildBeam(x - 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (rightbeam)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildBeam(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (toppillar)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildPillar(x, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}
			else if (toprightpillar)
			{
				//지우고 나서도 설치가 유효한가
				if (this->canBuildPillar(x + 1, y))
				{
					this->structure[x][y].setBeam(true);
					return true;
				}

				this->structure[x][y].setBeam(true);
				return false;
			}

			this->structure[x][y].setBeam(true);
			return true;
		}
	}
}
void Structure::BuildPillar(int x, int y)
{
	//중복 설치 확인 필요 -> 정말 필요한가?

	if (this->canBuildPillar(x, y))
	{
		this->structure[x][y].setPillar(true);
	}
}
void Structure::BuildBeam(int x, int y)
{
	//중복 설치 확인 필요 -> 정말 필요한가?

	if (this->canBuildBeam(x, y))
	{
		this->structure[x][y].setBeam(true);
	}
}
void Structure::DestroyPillar(int x, int y)
{
	if (this->canDestroyPillar(x, y))
	{
		this->structure[x][y].setPillar(false);
	}
}
void Structure::DestroyBeam(int x, int y)
{
	if (this->canDestroyBeam(x, y))
	{
		this->structure[x][y].setBeam(false);
	}
}
vector<vector<int>> Structure::getInfo()
{
	vector<vector<int>> ret;
	int x, y, state;
	for (int i = 0; i <= this->n; i++)
	{
		for (int j = 0; j <= this->n; j++)
		{
			if (this->structure[i][j].getBeam() == false &&
				this->structure[i][j].getPillar() == false)
			{
				continue;
			}
			
			if (this->structure[i][j].getPillar() == true)
			{
				x = i;
				y = j;
				state = 0;
				ret.push_back({ x, y, state });
			}

			if (this->structure[i][j].getBeam() == true)
			{
				x = i;
				y = j;
				state = 1;
				ret.push_back({ x, y, state });
			}
		}
	}

	return ret;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
	vector<vector<int>> answer;

	//벽면을 벗어나게 기둥, 보를 설치하는 경우는 없습니다.
	//바닥에 보를 설치 하는 경우는 없습니다.
	Structure* structure = new Structure(n);

	for (int i = 0; i < build_frame.size(); i++)
	{
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int kind = build_frame[i][2];
		int B_D_flag = build_frame[i][3];

		//0이면 기둥에 대한 내용
		if (kind == 0)
		{
			//0이면 삭제
			if (B_D_flag == 0)
			{
				structure->DestroyPillar(x, y);
			}
			//1이면 설치
			else
			{
				structure->BuildPillar(x, y);
			}
		}
		//1이면 보에 대한 내용
		else
		{
			//0이면 삭제
			if (B_D_flag == 0)
			{
				structure->DestroyBeam(x, y);
			}
			//1이면 설치
			else
			{
				structure->BuildBeam(x, y);
			}
		}
	}

	answer = structure->getInfo();

	return answer;
}
