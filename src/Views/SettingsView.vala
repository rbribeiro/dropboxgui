public class SettingsView : Gtk.Paned {

    public SettingsView() {
        var preferences_page = new SettingsPreferencesPage ();
        var preferences_dropbox_page = new SettingsDropboxPage ();
    
        var stack = new Gtk.Stack ();
        stack.add (preferences_page);
        stack.add (preferences_dropbox_page);
    
     var sidebar = new Granite.SettingsSidebar (stack);

     add(sidebar);
     add(stack);

    }
}
