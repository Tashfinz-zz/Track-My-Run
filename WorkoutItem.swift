//
//  WorkoutItem.swift
//  LFopen2Demo
//
//  Created by Tash Shahid on 03/10/2018.
//  Copyright © 2018 Lifefitness. All rights reserved.
//

import Foundation

class WorkoutItem{
    
    var distance: Double?
    var speed:  Double?
    var time:   Double?
    
    init (distance: Double?, speed: Double?,time: Double?){
        
        self.speed = speed
        self.distance = distance
        self.time = time
    }
}
