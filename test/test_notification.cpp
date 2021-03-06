// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

// ============================================================================
// Copyright (c) 2017-2018, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of ProtocolAnalyzer open source project under MIT License.
// ============================================================================

#include <iostream>

#include "../include/analyzer/System.hpp"
#include "../include/analyzer/Notification.hpp"

using namespace analyzer::task;
using namespace analyzer::system;


int32_t main (int32_t size, char** data)
{
    auto init = allocMemoryForObject<NotificationInit<uint16_t>>(117);
    if (init == nullptr) {
        return EXIT_FAILURE;
    }

    auto subject = init->ToSubject();
    subject->SetValue(116);

    NotificationObserver<uint16_t>* observer = subject->ToObserver();
    //NotificationObserver<uint16_t>* observer = init->ToObserver();
    std::cout << observer->Wait() << std::endl;


    return EXIT_SUCCESS;
}

