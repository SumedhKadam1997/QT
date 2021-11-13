var component
var sprite

function createPloyLine() {
    component = Qt.createComponent("navPathPolyLine.qml");
    if (component.status == Component.Ready)
        finishCreation();
    else
        component.statusChanged.connect(finishCreation);

}

function finishCreation() {
    if (component.status == Component.Ready) {
        sprite = component.createObject(map);
        map.addMapItem(sprite);
        if (sprite == null) {
            console.log("Error creating Object");
        }
    }
    else if (component.status == Component.Error) {
        console.log("Error loading component:", component.errorString());
    }
}

function deletePolyLine() {
    sprite.destroy()
}
