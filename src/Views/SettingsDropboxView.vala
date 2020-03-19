public class SettingsDropboxPage : Granite.SimpleSettingsPage {
    
    public SettingsDropboxPage () {
        Object (
            Icon : "system-preferences",
            title : "Dropbox Settings",
            header : "Advanced",
            description : "Desc"
        )
    }
    
    construct {
        var label = new Gtk.Label ("Oi");
        
        content_area.add(label);
    }
    
}
