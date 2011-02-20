#!/bin/sh

qdbusxml2cpp -c QTestableDBusAdaptor -a QTestableDBusAdaptor.h:QTestableDBusAdaptor.cpp org.qTestable.xml
