#!/bin/bash

find * -depth -type f -name "*.sh" -exec basename {} \; | sed "s|...$||"
