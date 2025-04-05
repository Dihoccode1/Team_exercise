#include <bits/stdc++.h>
using namespace std;

struct Examroom {
    int roomNumber;
    int capacity;
    char building;

    Examroom(int roomNumber = 0, int capacity = 0, char building = 'A') {
        this->roomNumber = roomNumber;
        this->capacity = capacity;
        this->building = building;
    }
};

void printRooms(const vector<Examroom>& rooms) {
    for (const auto& room : rooms) {
        cout << "Phòng " << room.roomNumber
             << ", Nhà " << room.building
             << ", Khả năng chứa " << room.capacity << endl;
    }
    cout << endl;
}

int partitionByCapacity(vector<Examroom>& rooms, int low, int high) {
    int pivot = rooms[high].capacity;
    int left = low;
    for (int i = low; i < high; i++) {
        if (rooms[i].capacity > pivot) {
            swap(rooms[i], rooms[left]);
            left++;
        }
    }
    swap(rooms[left], rooms[high]);
    return left;
}

void quickSortByCapacity(vector<Examroom>& rooms, int low, int high) {
    if (low < high) {
        int pivot = partitionByCapacity(rooms, low, high);
        quickSortByCapacity(rooms, low, pivot - 1);
        quickSortByCapacity(rooms, pivot + 1, high);
    }
}

int partitionByBuildingRoom(vector<Examroom>& rooms, int low, int high) {
    Examroom pivot = rooms[high];
    int left = low;
    for (int i = low; i < high; i++) {
        if (rooms[i].building < pivot.building || 
            (rooms[i].building == pivot.building && rooms[i].roomNumber < pivot.roomNumber)) {
            swap(rooms[i], rooms[left]);
            left++;
        }
    }
    swap(rooms[left], rooms[high]);
    return left;
}

void quickSortByBuildingRoom(vector<Examroom>& rooms, int low, int high) {
    if (low < high) {
        int pivot = partitionByBuildingRoom(rooms, low, high);
        quickSortByBuildingRoom(rooms, low, pivot - 1);
        quickSortByBuildingRoom(rooms, pivot + 1, high);
    }
}

int partitionByBuildingCapacity(vector<Examroom>& rooms, int low, int high) {
    Examroom pivot = rooms[high];
    int left = low;
    for (int i = low; i < high; i++) {
        if (rooms[i].building < pivot.building || 
            (rooms[i].building == pivot.building && rooms[i].capacity > pivot.capacity)) {
            swap(rooms[i], rooms[left]);
            left++;
        }
    }
    swap(rooms[left], rooms[high]);
    return left;
}

void quickSortByBuildingCapacity(vector<Examroom>& rooms, int low, int high) {
    if (low < high) {
        int pivot = partitionByBuildingCapacity(rooms, low, high);
        quickSortByBuildingCapacity(rooms, low, pivot - 1);
        quickSortByBuildingCapacity(rooms, pivot + 1, high);
    }
}

void test1() {
    vector<Examroom> rooms = {
        {103, 150, 'B'},
        {102, 200, 'A'},
        {101, 120, 'A'},
        {105, 180, 'B'},
        {104, 100, 'C'}
    };

    cout << "Test 1 - Trước khi sắp xếp:\n";
    printRooms(rooms);

    quickSortByCapacity(rooms, 0, rooms.size() - 1);
    cout << "Test 1 - Sắp xếp theo Khả năng chứa (Giảm dần):\n";
    printRooms(rooms);

    quickSortByBuildingRoom(rooms, 0, rooms.size() - 1);
    cout << "Test 1 - Sắp xếp theo Nhà (A → Z) & Số phòng (Tăng dần):\n";
    printRooms(rooms);

    quickSortByBuildingCapacity(rooms, 0, rooms.size() - 1);
    cout << "Test 1 - Sắp xếp theo Nhà (A → Z) & Khả năng chứa (Giảm dần):\n";
    printRooms(rooms);
}

void test2() {
    vector<Examroom> rooms = {
        {201, 100, 'C'},
        {105, 250, 'B'},
        {103, 180, 'B'},
        {101, 130, 'A'},
        {102, 220, 'A'}
    };

    cout << "Test 2 - Trước khi sắp xếp:\n";
    printRooms(rooms);

    quickSortByCapacity(rooms, 0, rooms.size() - 1);
    cout << "Test 2 - Sắp xếp theo Khả năng chứa (Giảm dần):\n";
    printRooms(rooms);

    quickSortByBuildingRoom(rooms, 0, rooms.size() - 1);
    cout << "Test 2 - Sắp xếp theo Nhà (A → Z) & Số phòng (Tăng dần):\n";
    printRooms(rooms);

    quickSortByBuildingCapacity(rooms, 0, rooms.size() - 1);
    cout << "Test 2 - Sắp xếp theo Nhà (A → Z) & Khả năng chứa (Giảm dần):\n";
    printRooms(rooms);
}

int main() {
    test1();
    // test2();
    return 0;
}