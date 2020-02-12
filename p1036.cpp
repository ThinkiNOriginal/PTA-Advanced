#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

struct Student {
	std::string name;
	std::string ID;
	int  grade;
	char        gender;
};

bool cmp (Student& s1, Student& s2) {
	return s1.grade < s2.grade;
}


int main() {
	
	int N;
	std::cin >> N;
	std::vector<Student> v(N);

	for (int i = 0; i < N; i++) {
		Student tmp;
		std::cin >> tmp.name >> tmp.gender >> tmp.ID >> tmp.grade;
		v[i] = tmp;
	}

	std::sort(v.begin(), v.end(), cmp); 

	Student* girl = nullptr;
	Student* boy  = nullptr;
	for (int i = 0; i < N; i++) {
		if (v[i].gender == 'M') {
			boy = &v[i];
			break;
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		if (v[i].gender == 'F') {
			girl = &v[i];
			break;
		}
	}
		
	if (girl)
		std::cout << girl -> name << " " << girl -> ID <<std::endl;
	else
		std::cout << "Absent" << std::endl;

	if (boy)
		std::cout << boy -> name << " " << boy -> ID << std::endl;
	else
		std::cout << "Absent" << std::endl;

	if (boy and girl)
		std::cout << girl -> grade - boy -> grade << std::endl;
	else
		printf("NA");


	return 0;
}


