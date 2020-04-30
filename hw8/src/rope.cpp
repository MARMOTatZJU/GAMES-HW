#include <iostream>
#include <vector>

#include "CGL/vector2D.h"

#include "mass.h"
#include "rope.h"
#include "spring.h"

namespace CGL {

    Rope::Rope(Vector2D start, Vector2D end, int num_nodes, float node_mass, float k, vector<int> pinned_nodes)
    {
        // TODO (Part 1): Create a rope starting at `start`, ending at `end`, and containing `num_nodes` nodes.
        
        Vector2D step_vec = (end - start) / (num_nodes - 1.0);
        
        Vector2D current_node=start;
        Vector2D previous_node; 
        Mass* current_mass = new Mass(current_node, node_mass, false);
        Mass* previous_mass = nullptr;
        masses.push_back(current_mass);
        Spring* current_spring = nullptr;
        for (auto ith=1;ith<=num_nodes;++ith)
        {
            // std::clog << num_nodes << std::endl;
            if (ith != num_nodes)
            {
                current_node = start + ith*step_vec;
            }
            else
            {
                current_node = end;
            }
            previous_mass = current_mass;
            current_mass = new Mass(current_node, node_mass, false);
            current_spring = new Spring(previous_mass, current_mass, k);
            // append current mass and spring
            masses.push_back(current_mass);
            springs.push_back(current_spring);
        }

//        Comment-in this part when you implement the constructor
       for (auto &i : pinned_nodes) {
           masses[i]->pinned = true;
       }
    }

    void Rope::simulateEuler(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            // TODO (Part 2): Use Hooke's law to calculate the force on a node
        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                // TODO (Part 2): Add the force due to gravity, then compute the new velocity and position

                // TODO (Part 2): Add global damping
            }

            // Reset all forces on each mass
            m->forces = Vector2D(0, 0);
        }
    }

    void Rope::simulateVerlet(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            // TODO (Part 3): Simulate one timestep of the rope using explicit Verlet （solving constraints)
        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                Vector2D temp_position = m->position;
                // TODO (Part 3.1): Set the new position of the rope mass
                
                // TODO (Part 4): Add global Verlet damping
            }
        }
    }
}