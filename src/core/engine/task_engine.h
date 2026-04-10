#pragma once

/*
=========================================================
 TaskEngine - Core System Controller (Taskr)
=========================================================

 This class will become the central controller for Taskr.

 Future responsibilities:
 - Manage automation state
 - Coordinate input, recorder, and player systems
 - Handle execution flow
=========================================================
*/

class TaskEngine {
public:
    TaskEngine();
    ~TaskEngine();

    // Core lifecycle
    void initialize();
    void shutdown();

    // Future update loop (automation tick system)
    void update();
};