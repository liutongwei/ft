
add_library(component STATIC
    order_book/order_book.cpp
    order_book/price_level.cpp
    pubsub/zmq_socket.cpp
    pubsub/publisher.cpp
    pubsub/subscriber.cpp
    position_calculator.cpp)
add_library(ft::component ALIAS component)

target_include_directories(component PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(component PUBLIC ft::ft_header ft::base cereal)
