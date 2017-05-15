"use strict"
log("test-new-jsb begin ...");

function iterateObject(obj, indent) {
  indent = indent || 0;
  for (var key in obj) {
    if (!obj.hasOwnProperty(key)) {
      continue;
    }
    var promote = " ";
    for (var i = 0; i < indent; ++i) {
      promote += "> ";
    }
    log(promote + "[" + key + "]=" + obj[key]);
    if (obj[key] instanceof Object) {
      iterateObject(obj[key], indent + 1);
    }
  }
}

log("before1");
iterateObject(cc.Scene.prototype);
log("after1");


// log("before1");
// iterateObject(cc.Node.prototype);
// log("after1");

// cc.Node.prototype.aa = 11;

// var node = new cc.Node();
// iterateObject(node.__proto__);
// log(node.aa);
// node.aa = 22;
// log(node.aa);
// log(node.__proto__.aa);
// log(cc.Node.prototype.aa);
// cc.Node.prototype.aa = 22;
// log("2:" + node.__proto__.aa);
// log("2:" + cc.Node.prototype.aa);

// log("before2");
// iterateObject(cc.Node.__proto__);
// log("after2");

var initializing = false;
var fnTest;

var window = window || this;
var cc = cc || {};
/**
 * @namespace jsb
 * @name jsb
 */
var jsb = jsb || {};

var arr = [];
var a_arr = [];

var ClassManager = {
  id: (0 | (Math.random() * 998)),

  instanceId: (0 | (Math.random() * 998)),

  getNewID: function() {
    return this.id++;
  },

  getNewInstanceId: function() {
    return this.instanceId++;
  }
};
//
// 2) Using "extend" subclassing
// Simple JavaScript Inheritance By John Resig http://ejohn.org/
//
cc.Class = function() {};
cc.Class.extend = function(prop) {
  var _super = this.prototype,
    prototype, Class, classId,
    className = prop._className || "",
    name, desc;

  // Instantiate a base class (but only create the instance,
  // don't run the init constructor)
  initializing = true;
  prototype = Object.create(_super);
  initializing = false;
  fnTest = /xyz/.test(function() {
    xyz;
  }) ? /\b_super\b/ : /.*/;

  // Copy the properties over onto the new prototype
  // log("---------------");
  for (name in prop) {
    // log("[" + name + "]");
    // Check if we're overwriting an existing function
    prototype[name] = typeof prop[name] == "function" &&
      typeof _super[name] == "function" && fnTest.test(prop[name]) ?
      (function(name, fn) {
        return function() {
          var tmp = this._super;

          // Add a new ._super() method that is the same method
          // but on the super-class
          this._super = _super[name];

          // The method only need to be bound temporarily, so we
          // remove it when we're done executing
          var ret = fn.apply(this, arguments);
          this._super = tmp;

          return ret;
        };
      })(name, prop[name]) :
      prop[name];
  }

  Class = function() {
    if (!initializing) {
      this.__instanceId = ClassManager.getNewInstanceId();
      this.ctor && this.ctor.apply(this, arguments);
    }
  };
  // Populate our constructed prototype object
  Class.prototype = prototype;
  // Enforce the constructor to be what we expect
  Class.prototype.constructor = Class;
  // And make this class extendable
  Class.extend = cc.Class.extend;

  classId = ClassManager.getNewID();
  ClassManager[classId] = _super;
  desc = {
    writable: true,
    enumerable: false,
    configurable: true
  };
  Class.id = classId;
  desc.value = classId;
  Object.defineProperty(prototype, '__pid', desc);

  return Class;
};

jsb.registerNativeRef = function(owner, target) {
  // log("jsb.registerNativeRef ... owner: " + owner + ", target: " + target);
  if (owner && target && owner !== target) {
    var refs = owner.__nativeRefs;
    if (!refs) {
      refs = owner.__nativeRefs = [];
    }
    var index = refs.indexOf(target);
    if (index === -1) {
      owner.__nativeRefs.push(target);
    } else {
      log("jsb.registerNativeRef, found target, don't push.");
    }
  }
};

jsb.unregisterNativeRef = function(owner, target) {
  log("jsb.unregisterNativeRef ... owner: " + owner + ", target: " + target);
  if (owner && target && owner !== target) {
    var refs = owner.__nativeRefs;
    if (!refs) {
      return;
    }
    var index = refs.indexOf(target);
    if (index !== -1) {
      log("jsb.unregisterNativeRef, splice ...");
      owner.__nativeRefs.splice(index, 1);
    }
  }
};

cc.Node.extend = cc.Class.extend;
cc.Sprite.extend = cc.Class.extend;
cc.Scene.extend = cc.Class.extend;

var __sceneIndex = 0;
var __spriteId = 0;

cc.Sprite.prototype._ctor = function(filePath) {
  log("cc.Sprite.prototype._ctor");
  var ok = this.initWithFile(filePath);
  log(ok);
}

cc.Scene.prototype._ctor = function() {
  log("cc.Scene.prototype._ctor");
  var ok = this.init();
  log(ok);
}

var MyScene = cc.Scene.extend({
  ctor: function() {
    log("MyScene ctor ...");
    this._super();
  },
  onEnter: function() {
    log("MyScene onEnter ...");
    this._super();
  },
  onExit: function() {
    log("MyScene onExit ...");
    this._super();
  },
  onEnterTransitionDidFinish: function() {
    this._super();
    log("MyScene onEnterTransitionDidFinish, this: " + this);
  },
  onExitTransitionDidStart: function() {
    this._super();
    log("MyScene onExitTransitionDidStart, this: " + this);
  }
});

var MySprite = cc.Sprite.extend({
  id: 0,
  ctor: function(file) {
    this.id = __spriteId++;
    log("MySprite ------> In the ctor of MySprite: id:" + this.id);
    this._super(file);
    log("MySprite ------> after this._super: id:" + this.id);
  },
  onEnter: function() {
    log("MySprite onEnter1 ...: id:" + this.id);
    this._super();
    log("MySprite onEnter2 ...: id:" + this.id);
  },
  onExit: function() {
    log("MySprite onExit1 ...: id:" + this.id);
    this._super();
    log("MySprite onExit2 ...: id:" + this.id);
  }
});

log("start THIS: " + this);

(function() {
  log("test start ...: THIS: " + this);

  function runScene() {
    log("runScene start ...: THIS: " + this);
    forceGC();

    var scene = new cc.Scene();
    // var sp = cc.Sprite.create("res/Images/arrows.png");

    // log("before get x");
    // log("x:" + sp.x);
    // log("after get x");
    // sp.x = 400;
    // sp.y = 400;
    // log("x:" + sp.x);
    // scene.addChild(sp);

    log("cc.Sprite: " + cc.Sprite);
    log("cc.Node: " + cc.Node);
    // log("sp instanceof cc.Sprite: " + (sp instanceof cc.Sprite));
    // log("sp instanceof cc.Node: " + (sp instanceof cc.Node));
    // log("sp instanceof cc.Menu: " + (sp instanceof cc.Menu));
    // log("typeof(sp): " + typeof(sp));
    // log("" + sp);

    // var garbageNode = cc.Node.create();
    // var tempSp = cc.Sprite.create("res/Images/arrows.png");

    // var oldOnEnter = cc.Scene.prototype.onEnter;
    // var oldOnExit = cc.Scene.prototype.onExit;
    // var oldOnEnterTransitionDidFinish = cc.Scene.prototype.onEnterTransitionDidFinish;
    // var oldOnExitTransitionDidStart = cc.Scene.prototype.onExitTransitionDidStart;
    // var oldCleanup = cc.Scene.prototype.cleanup;



    // var sp2 = new cc.Sprite("res/Images/arrows.png");
    // sp2.x = 40;
    // sp2.y = 200;

    // scene.addChild(sp2);

    log("this: " + this);

    log("begin cc.Sprite.test_static_property = " + cc.Sprite.test_static_property);
    cc.Sprite.test_static_property = 23;
    log("after cc.Sprite.test_static_property = " + cc.Sprite.test_static_property);


    var sp3 = new MySprite("res/Images/arrows.png");

    scene.addChild(sp3);
    // log("before iterate MySprite ...");
    // iterateObject(MySprite.prototype.__proto__);
    // log("after iterate MySprite ...");
    log("before sp3.x:" + sp3.x + ", y:" + sp3.y);
    sp3.x = 20;
    sp3.y = 300;
    log("after sp3.x:" + sp3.x + ", y:" + sp3.y);
    log("native ------ test ");

    log("before iterate scene ...");
    iterateObject(scene);
    log("after iterate scene ...");

    // scene.onEnter = function() {
    //   log("JS onEnter, this: " + scene);
    //   oldOnEnter.apply(scene);
    //   log("JS onEnter 2");
    // };
    // scene.onExit = function() {
    //   log("JS onExit, this: " + this);
    //   oldOnExit.apply(this);
    // };

    // scene.onEnterTransitionDidFinish = function() {
    //   log("JS onEnterTransitionDidFinish, this: " + this);
    //   oldOnEnterTransitionDidFinish.apply(this);
    // };

    // scene.onExitTransitionDidStart = function() {
    //   log("JS onExitTransitionDidStart, this: " + this);
    //   oldOnExitTransitionDidStart.apply(this);
    // };

    // scene.cleanup = function() {
    //   log("JS cleanup, this: " + scene);
    //   oldCleanup.apply(scene);
    // };

    var fn = function(dt) {
      log("schedule updated 1: " + scene);
    };

    var fn2 = function(dt) {
      log("schedule updated 2: " + scene);
    };

    // var a = new MyNode;
    // scene.addChild(a);



    var menu = cc.Menu.create();
    scene.addChild(menu);

    var item = null;

    item = cc.MenuItemFont.create("unschedule1", function(sender) {
      // log("menu item clicked!, sender: " + sender + ", this: " + this + ",id=" + sender.id);
      scene.unschedule(fn);
      var aaa = cc.Node.create();
      forceGC();
    }, scene);
    item.id = "item1:" + __sceneIndex;
    menu.addChild(item);

    item = cc.MenuItemFont.create("schedule1", function(sender) {
      log("scene: " + scene);
      scene.schedule(fn, 1);
    }, scene);
    item.id = "item1:" + __sceneIndex;
    item.y += 100;
    menu.addChild(item);

    item = cc.MenuItemFont.create("unschedule2", function(sender) {
      // log("menu item clicked!, sender: " + sender + ", this: " + this + ",id=" + sender.id);
      scene.unschedule(fn2);
    }, scene);
    item.id = "item1:" + __sceneIndex;
    item.x -= 200;
    menu.addChild(item);

    item = cc.MenuItemFont.create("schedule2", function(sender) {
      scene.schedule(fn2, 1);
    }, scene);
    item.id = "item1:" + __sceneIndex;
    item.x -= 200;
    item.y += 100;
    menu.addChild(item);

    item = cc.MenuItemFont.create("New Scene " + __sceneIndex, function(sender) {
      log("New Scene clicked!, sender: " + sender + ", this: " + this + ",id=" + sender.id);
      runScene();
    }, scene);
    item.id = "item2:" + __sceneIndex;
    item.y -= 100;
    menu.addChild(item);

    var director = cc.Director.getInstance();
    if (__sceneIndex == 0) {
      director.runWithScene(scene);
    } else {
      director.replaceScene(scene);
    }

    forceGC();
    __sceneIndex++;
    log("runScene end ...");
  }

  runScene();

  forceGC();
  log("after gc");


  // iterateObject(this, 0);

  // var _id = 0;
  // // log("h22222");
  // // var dog = new Dog(100, "hello");
  // // dog.name = "Snickers";
  // // dog.age = 100;
  // // dog.testFunc();
  // // dog.eat();

  // function A(animal) {
  //   this.animal = animal;
  //   this.id = animal.id;
  // }

  // A.prototype = {
  //   onTimeout: function() {
  //     log("onTimeout, id = " + this.id + ", animalid: " + this.animal.id);

  //     {

  //       // for (var i = 0; i < 100; ++i) {
  //       //   var animal = new Animal();
  //       //   var bbb = new A(animal);
  //       //   bbb.id = _id++;
  //       //   animal.id = bbb.id;
  //       //   log("new Animal: id: " + animal.id);
  //       //   // animal.setTimeout(0.1, bbb.onTimeout, bbb);
  //       //   if (this.id % 10 == 0) {
  //       //     // forceGC();
  //       //   }
  //       // }
  //       this.animal.setTimeout(1, A.prototype.onTimeout, this, this.animal);
  //       // forceGC();
  //     }
  //   },

  //   id: 0,
  //   animal: 0
  // };

  // for (var i = 0; i < 50; ++i) {
  //   var animal = new Animal();

  //   animal.id = _id++;
  //   var aaa = new A(animal);

  //   if (animal.id % 2 == 0) {
  //     // arr.push(animal);
  //     // a_arr.push(aaa);
  //     aaa.id = animal.id;
  //     animal.setTimeout(2, aaa.onTimeout, aaa, animal);
  //   } else {
  //     animal.eat();
  //   }
  //   //var a = new Animal();
  //   //a.id = animal.id + 10000;

  // }
  // forceGC();
  // log("test end...");

})();