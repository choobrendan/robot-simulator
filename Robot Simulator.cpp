class robot {

	int xValue;
	int yValue;
	string direction;
	int msize;


public:
	robot() {

		xValue = 0;
		yValue = 0;
		direction = "North";
		msize = 0;

	}
	void setxValue(int setx) {

		xValue = setx;

	}
	void setyValue(int sety) {

		yValue = sety;

	}
	void setdirection(string adirection) {

		direction = adirection;

	}
	void setsize(int size) {
		msize = size;
	}
	int getxValue() {

		return xValue;

	}
	int getyValue() {

		return yValue;

	}
	string getdirection() {

		return direction;

	}
	char change(string movement, char arr[]) {
		int size = movement.size();
		char* p = new char[size];
		for (int i = 0; i < movement.size(); i++) {
			p[i] = movement[i];
		}
		for (int i = 0; i < movement.size(); i++) {
			arr[i] = p[i];
		}
		return *arr;
		delete[]p;
	}
	enum direct { North = 1, East = 2, South = 3, West = 4 };
	direct getenum(string direction) {
		if (direction == "North" || direction == "north") return North;
		if (direction == "South" || direction == "south") return South;
		if (direction == "East" || direction == "east") return East;
		if (direction == "West" || direction == "west") return West;
	}
	void getDirection(int i, char arr[]) {

		int temp;

		direct point;
		point = getenum(direction);
		temp = point;
		if (arr[i] == 'l' || *(arr + i) == 'L') {
			temp--;
			if (temp == 0) {
				temp = temp + 4;
			}
		}
		if (*(arr + i) == 'r' || *(arr + i) == 'R') {
			temp++;
			if (temp == 4) {
				temp = temp - 4;
			}
		}
		switch (temp) {
		case 1:
			direction = "North";
			break;
		case 2:
			direction = "East";
			break;
		case 3:
			direction = "South";
			break;
		case 4:
			direction = "West";
			break;
		}
	}
	void setxy(int i, char arr[]) {
		if (arr[i] == 'A') {
			if (direction == "North") {
				yValue++;
			}
			else if (direction == "South") {
				yValue--;
			}
			if (direction == "East") {
				xValue++;
			}
			if (direction == "West") {
				yValue--;
			}
		}

	}
};

int main() {
	int setx, sety;
	string startd, movement;
	robot robot1;
	cout << "set x" << endl;
	cin >> setx;
	cout << "set y" << endl;
	cin >> sety;
	cout << "starting direction" << endl;
	cin >> startd;
	robot1.setxValue(setx);
	robot1.setyValue(sety);
	robot1.setdirection(startd);
	cout << "Directions" << endl;
	cin >> movement;
	int size = movement.size();
	robot1.setsize(size);
	char* arr = new char[size];
	robot1.change(movement, arr);
	for (int i = 0; i < size; i++) {
		robot1.getDirection(i, arr);
		robot1.setxy(i, arr);
	}

	cout << robot1.getdirection();
	cout << " {" << robot1.getxValue() << "," << robot1.getyValue() << "}" << endl;

	delete[]arr;

}