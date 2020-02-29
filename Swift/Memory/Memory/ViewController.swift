//
//  ViewController.swift
//  Memory
//
//  Created by Kutyba Król on 08.09.2016.
//  Copyright © 2016 Kablociag Syrek i spolka. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        let dest = segue.destinationViewController as! ViewController2
        if(segue.identifier == "e"){
            dest.tryb = 1
        }else{
            dest.tryb = 2
        }
    }

}

