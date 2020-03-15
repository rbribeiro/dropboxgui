public class SettingsView : Gtk.Paned {

    public SettingsView() {
    var preferences_page = new SettingsPreferencesPage ();
    
        var stack = new Gtk.Stack ();
        stack.add (preferences_page);
    
    
     var sidebar = new Granite.SettingsSidebar (stack);

     add(sidebar);
     add(stack);

    }
}
