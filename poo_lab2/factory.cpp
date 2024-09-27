#include "factory.h"

void factory::showQueues()
{

    if (queues.size()) {
        cout << "\n\nNumber of queues: " << queues.size() << "\n";
        VariadicTable<short, string, int, int, int, int> vt({ "ID", "Name", "max", "free", "Volumul Total", "Suprafata totala"}, 10);
        for (size_t i = 0; i < queues.size(); ++i) {
            vt.addRow(i+1, queues[i].name, queues[i].limit, queues[i].free, queues[i].total_volume, queues[i].total_surface);
        }
        vt.print(cout);
    }else {
        cout << "NO QUEUES\n\n\n";
    }
}

void factory::showBoxes()
{
    system("cls");
    cout << "introduceti ID Randului cutiilor (0 pentru lista intreaga)\n";
    int show_id;
    cin >> show_id;
    if (boxes.size()) {
        cout << "Number of queues: " << boxes.size() << "\n";
        VariadicTable<int, int, int, int> vt({ "ID", "intaltime", "latime", "adancime"}, 10);
        for (size_t i = 0; i < boxes.size(); ++i) {
            if ((boxes[i].lineID == show_id) || (show_id == 0)) {
                vt.addRow(boxes[i].lineID, boxes[i].height, boxes[i].width, boxes[i].depth);
            }
        }
        vt.print(cout);
    }
    else {
        cout << "NO BOXSES\n\n\n";
    }
    pressToMenu();
}


void factory::addQueue(){
    system("cls");
    lineSturct newQueue;
    cout << "Introduceti numele randului\n";
    cin >> newQueue.name;
    cout << "Introduceti numarul maxim de cutii (0 pentru infinit)\n";
    cin >> newQueue.limit;
    newQueue.free = newQueue.limit;
    newQueue.total_volume = 0;
    newQueue.total_surface = 0;
    queues.push_back(newQueue);
    system("cls");
}


void factory::addBox()
{
    system("cls");
    object new_box;
    cout << "intrudceti ID la rand la care doriti sal atribuiti:\n";
    cin >> new_box.lineID;


    if (new_box.lineID > queues.size() || new_box.lineID < 0) {     //error trobleshooting
        cout << "acest sir nu exista!\n";
    }
    else if(!queues[new_box.lineID - 1].free)                        //error trobleshooting
    {
        cout << "randul e plin!\n";
    }
    else {
        queues[new_box.lineID - 1].free--;
        cout << "introduceti tipul de cutie (with, height, depth)\n";
        cout << "1. toate parametrele = 1\n";
        cout << "2. toate parametrele egale cu valoarea introdusa\n";
        cout << "3. introduceti fiecare parametru\n";
        int boxMode;
        cin >> boxMode;

        switch (boxMode)
        {
        case 1:
            new_box.depth = 1;
            new_box.height = 1;
            new_box.width = 1;
            boxes.push_back(new_box);


            queues[new_box.lineID - 1].total_volume += new_box.depth* new_box.height* new_box.width;
            queues[new_box.lineID - 1].total_surface += (2 * new_box.depth * new_box.height) + (2 * new_box.depth * new_box.width) + (2 * new_box.height * new_box.width);

            system("cls");
            cout << "Cutia a fost introdusa cu succes!\n";
            cout << "Datele cutiei introduse:\n";
            cout << "volumul:" << new_box.depth * new_box.height * new_box.width << "  suprafata:" << (2 * new_box.depth * new_box.height) + (2 * new_box.depth * new_box.width) + (2 * new_box.height * new_box.width);
            break;
        case 2:
            cout << "Introduceti parametrul\n";
            cin >> new_box.depth;
            new_box.height = new_box.depth;
            new_box.width = new_box.depth;
            boxes.push_back(new_box);

            queues[new_box.lineID - 1].total_volume += new_box.depth * new_box.height * new_box.width;
            queues[new_box.lineID - 1].total_surface += (2 * new_box.depth * new_box.height) + (2 * new_box.depth * new_box.width) + (2 * new_box.height * new_box.width);

            system("cls");
            cout << "Cutia a fost introdusa cu succes!\n";
            cout << "Datele cutiei introduse:\n";
            cout << "volumul:" << new_box.depth * new_box.height * new_box.width << "  suprafata:" << (2 * new_box.depth * new_box.height) + (2 * new_box.depth * new_box.width) + (2 * new_box.height * new_box.width);
            break;
        case 3:
            cout << "\nIntroduceti inaltimea\n";
            cin >> new_box.height;

            cout << "\nIntroduceti latimea\n";
            cin >> new_box.width;

            cout << "\nIntroduceti adancimea\n";
            cin >> new_box.depth;
            boxes.push_back(new_box);


            queues[new_box.lineID - 1].total_volume += new_box.depth * new_box.height * new_box.width;
            queues[new_box.lineID - 1].total_surface += (2 * new_box.depth * new_box.height) + (2 * new_box.depth * new_box.width) + (2 * new_box.height * new_box.width);

            system("cls");
            cout << "Cutia a fost introdusa cu succes!\n";
            cout << "Datele cutiei introduse:\n";
            cout << "volumul:" << new_box.depth * new_box.height * new_box.width << "  suprafata:" << (2 * new_box.depth * new_box.height) + (2 * new_box.depth * new_box.width) + (2 * new_box.height * new_box.width);
            break;
        default:
            break;
        }
    }
}

void factory::pop()
{
    system("cls");
    this->showQueues();
    cout << "introducti ID rindului la care prima cutie o sa fie stearsa\n";
    int boxline_to_delete = 0;
    cin >> boxline_to_delete;

    int index = -1;
    for (int i = 0; i < boxes.size(); ++i) {
        if (boxes[i].lineID == boxline_to_delete) {
            index = i;
            break;
        }
    }


    system("cls");

    if (index != -1) {
        queues[boxline_to_delete-1].total_volume -= boxes[index].depth * boxes[index].height * boxes[index].width;
        queues[boxline_to_delete-1].total_surface -= (2 * boxes[index].depth * boxes[index].height) + (2 * boxes[index].depth * boxes[index].width) + (2 * boxes[index].height * boxes[index].width);
        boxes.erase(boxes.begin() + index);
        cout << "curia a fost stearsa";
    }
    else {
        cout << "cutii nu sunt";
    }
}

