#include <behaviortree_cpp/bt_factory.h>
#include <iostream>
#include <fstream>

using namespace BT;

int main()
{
    BehaviorTreeFactory factory;
    factory.registerFromPlugin("./libactions.so");

    auto tree = factory.createTreeFromFile("tree.xml");

    // Tick the root once
    NodeStatus status = tree.tickOnce();

    std::cout << "Behavior Tree finished with status: "
              << toStr(status) << std::endl;

    return 0;
}
