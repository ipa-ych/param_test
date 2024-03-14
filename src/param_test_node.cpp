#include "rclcpp/rclcpp.hpp"
#include "rclcpp/parameter_map.hpp"

class ParameterNode : public rclcpp::Node {
public:
    ParameterNode() : Node("parameter_node") {

        // this->declare_parameter("diagnostics", rclcpp::ParameterMap());

        this->declare_parameter("topics", std::vector<std::string>());
        this->declare_parameter("can_device", std::string());
        this->declare_parameter("bms_id_to_poll", int());
        this->declare_parameter("poll_frequency_hz", int());

        // diagnostics_ = this->get_parameter("diagnostics").as_();
        topics_ = this->get_parameter("topics").as_string_array();
        can_device_ = this->get_parameter("can_device").as_string();
        bms_id_to_poll_ = this->get_parameter("bms_id_to_poll").as_int();
        poll_frequency_hz_ = this->get_parameter("poll_frequency_hz").as_int();

        if (this->get_parameter("can_device", can_device_))
        {
            RCLCPP_INFO(this->get_logger(), "Get CAN Device");
            can_device_ = "can0";
        }        


        // this->get_parameter("bms_id_to_poll", bms_id_to_poll_);
        // this->get_parameter("poll_frequency_hz", poll_frequency_hz_);

        // Display retrieved parameters
        //RCLCPP_INFO(this->get_logger(), "Diagnostics: %s", diagnostics_.to_string().c_str());

        RCLCPP_INFO(this->get_logger(), "Topics: ");
        for (const auto& topic : topics_) {
            RCLCPP_INFO(this->get_logger(), "  %s", topic.c_str());
        }        

        RCLCPP_INFO(this->get_logger(), "CAN Device: %s", can_device_.c_str());
        RCLCPP_INFO(this->get_logger(), "BMS ID to Poll: %d", bms_id_to_poll_);
        RCLCPP_INFO(this->get_logger(), "Poll Frequency (Hz): %d", poll_frequency_hz_);
    }

private:
    rclcpp::ParameterMap diagnostics_;
    std::vector<std::string> topics_;
    std::string can_device_;
    int bms_id_to_poll_;
    int poll_frequency_hz_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ParameterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
