#include <behaviortree_cpp/bt_factory.h>
#include <iostream>

using namespace BT;

class EnterRoom : public SyncActionNode
{
public:
    EnterRoom(const std::string& name, const NodeConfiguration& config)
        : SyncActionNode(name, config) {}
    NodeStatus tick() override
    {
        std::cout << "Entering the room..." << std::endl;
        return NodeStatus::SUCCESS;
    }
};

class OpenFridge : public SyncActionNode
{
public:
    OpenFridge(const std::string& name, const NodeConfiguration& config)
        : SyncActionNode(name, config) {}
    NodeStatus tick() override
    {
        std::cout << "Opening the fridge..." << std::endl;
        return NodeStatus::SUCCESS;
    }
};

class PickApple : public SyncActionNode
{
public:
    PickApple(const std::string& name, const NodeConfiguration& config)
        : SyncActionNode(name, config) {}
    NodeStatus tick() override
    {
        std::cout << "Picking the apple..." << std::endl;
        return NodeStatus::SUCCESS;
    }
};

class ExitRoom : public SyncActionNode
{
public:
    ExitRoom(const std::string& name, const NodeConfiguration& config)
        : SyncActionNode(name, config) {}
    NodeStatus tick() override
    {
        std::cout << "Exiting the room..." << std::endl;
        return NodeStatus::SUCCESS;
    }
};

BT_REGISTER_NODES(factory)
{
    factory.registerNodeType<EnterRoom>("EnterRoom");
    factory.registerNodeType<OpenFridge>("OpenFridge");
    factory.registerNodeType<PickApple>("PickApple");
    factory.registerNodeType<ExitRoom>("ExitRoom");
}
