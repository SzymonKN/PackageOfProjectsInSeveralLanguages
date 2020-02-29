//
//  ViewController2.swift
//  Memory
//
//  Created by Kutyba Król on 08.09.2016.
//  Copyright © 2016 Kablociag Syrek i spolka. All rights reserved.
//

import UIKit


extension Array {
    mutating func shuffle() {
        if count < 2 { return }
        for i in 0..<(count - 1) {
            let j = Int(arc4random_uniform(UInt32(count - i))) + i
            guard i != j else { continue }
            swap(&self[i], &self[j])
        }
    }
}


class ViewController2: UIViewController {
    var tryb : Int?
    var tabl : [Int] = []
    var tab=["a.jpg","a.jpg","b.jpg","b.jpg","c.jpg","c.jpg","d.jpg","d.jpg","e.jpg","e.jpg","f.jpg","f.jpg","g.jpg","g.jpg","h.jpg","h.jpg","i.jpg","i.jpg","j.jpg","j.jpg","k.jpg","k.jpg","l.jpg","l.jpg",]
    var tag1 = -1
    var tag2 = -1
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        let sz = UIScreen.mainScreen().bounds
         var licznik = 0
        if(tryb == 1){
            tabl = [0,1,2,3,4,5,6,7,8,9,10,11]
            tabl.shuffle()
            for jndex in 0...3 {
                for index in 0...2 {
                    let but : UIButton = UIButton()
                    but.backgroundColor = UIColor.blackColor()
                    let www = Int((navigationController?.navigationBar.bounds.height)!)
                    let wwww = Int(UIApplication.sharedApplication().statusBarFrame.height)
                    let wwwww = (www + wwww)
                    let uu = (Int(sz.height) - Int(sz.width) / 3 * 4 - wwwww)
                    let wdt = Int(sz.width) / 3 - 3
                    but.frame = CGRect(x: 2+2*index + (wdt * index ), y:jndex*2+uu + (wdt * jndex) , width: wdt, height: wdt)
                    but.addTarget(self, action: #selector(akcja), forControlEvents: .TouchUpInside)
                    but.setBackgroundImage(UIImage(named: "img/latest.jpg"), forState: .Normal)
                    self.view.addSubview(but)
                    but.tag = tabl[licznik]
                    licznik += 1
                }
            }
        }else{
            
            tabl=[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23]
            tabl.shuffle()
            for jndex in 0...5 {
                for index in 0...3 {
                    let but : UIButton = UIButton()
                    but.backgroundColor = UIColor.blackColor()
                    let www = Int((navigationController?.navigationBar.bounds.height)!)
                    let wwww = Int(UIApplication.sharedApplication().statusBarFrame.height)
                    let wwwww = (www + wwww)
                    let uu = (Int(sz.height) - (Int(sz.width) / 4) * 6 - wwwww/3)
                    let wdt = Int(sz.width) / 4 - 3
                    but.frame = CGRect(x: 2+2*index + (wdt * index ), y:jndex*2+uu + (wdt * jndex) , width: wdt, height: wdt)
                    but.addTarget(self, action: #selector(akcja), forControlEvents: .TouchUpInside)
                    but.setBackgroundImage(UIImage(named: "img/latest.jpg"), forState: .Normal)
                    self.view.addSubview(but)
                    but.tag = tabl[licznik]
                    licznik += 1
                }
            }
        }
    }
    func akcja(sender : UIButton){
       sender.setBackgroundImage(UIImage(named: "img/"+tab[tabl[sender.tag]]), forState: .Normal)
        print(sender.tag)
        tag1 = tag2
        tag2 = sender.tag
        if(tag2==tag1){
            print("WOW")
        }
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
