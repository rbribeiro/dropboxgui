public class SettingsDropboxPage : Granite.SimpleSettingsPage {
    
    public SettingsDropboxPage () {
        Object (
            icon_name : "preferences-system",
            title : "Dropbox Settings",
            header : "Advanced Settings",
            description : "Desc",
            status : "Searching...",
            activatable : true
        );
    }
    
    construct {
        var label = new Gtk.Label ("Oi");
        
        content_area.add(label);
    }
    
}
