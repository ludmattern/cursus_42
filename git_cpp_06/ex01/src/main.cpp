/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:48 by lmattern          #+#    #+#             */
/*   Updated: 2024/07/20 21:03:23 by lmattern         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Data.hpp"
#include "../include/Serializer.hpp"

int main(void) {
    Data originalData = {42, 3.14f, "Test Object"};

    // Serialize the pointer to originalData
    uintptr_t serializedData = Serializer::serialize(&originalData);

    // Deserialize the raw value back to a pointer
    Data* deserializedData = Serializer::deserialize(serializedData);

    // Check if the deserialized pointer is equal to the original pointer
    if (deserializedData == &originalData) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Data ID: " << deserializedData->id << std::endl;
        std::cout << "Data Value: " << deserializedData->value << std::endl;
        std::cout << "Data Name: " << deserializedData->name << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}
