$.ajaxSetup({beforeSend: function(xhr){
  if (xhr.overrideMimeType)
  {
    xhr.overrideMimeType("application/json");
  }
}
});

$.getJSON('specs.json', function(specs) {
    for (var elName in specs.element) {
        console.log('Testing Element.'+elName);
        var element = specs.element[elName]
        console.log('\t# Properties');
        for (var name in element.properties) {
            var property = element.properties[name];
            console.log('\t\tTesting "'+name+'"')
        }
        console.log('\t# Methods');
        for (var name in element.methods) {
            var method = element.methods[name];
            console.log('\t\tTesting "'+name+'('+(method.args?method.args.join(', '):'')+')"')
        }
    }
})
