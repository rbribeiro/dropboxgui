public class Dropbox : GLib.Object {

    public string[] status = {"", "", ""};
    private double total_number_files_syncing = 0;
    private double actual_number_files_syncing = 0;
    private double percent = 0;
    private string prev_status_text = "p";

    public signal void status_changed (string[] s);

    public void emit_status_change (string[] s) {
        status_changed (s);
    }

    public Dropbox () {
        
    }

    public void timeout (int interval) {
        GLib.Timeout.add (interval, core);
    }
    private bool core () {

        try {
            string[] args = {"dropbox", "status"};
            string stdout;
            string stderr;
            int result;

            Process.spawn_sync("/", args, null, SpawnFlags.SEARCH_PATH, null, out stdout, out stderr, out result);
            string[] str = stdout.split("\n");
            int index = str.length -2;
      
            status[0] = str[index].split(" ")[0];
            status[1] = str[index];
                     
            if (prev_status_text != status[1] ) {
                prev_status_text = status[1];
                emit_status_change (status);
            }
            
             if(status[0] == "Uploading" || status[0] == "Indexing" || status[0] == "Syncing" || status[0] == "Downloading") {
         
                 string files = status[1].split(" ")[1];
                 string first_char = files[0].to_string();
            
                 if(first_char in "1 2 3 4 5 6 7 8 9") {
                     double n = double.parse(files);
                     if(n > total_number_files_syncing) {
                         total_number_files_syncing = n;
                         percent = actual_number_files_syncing/total_number_files_syncing;
                         status[2] = percent.to_string();

                     } else if(n<total_number_files_syncing) {
                         actual_number_files_syncing = n;
                         percent = 1 - actual_number_files_syncing/total_number_files_syncing;
                         status[2] = percent.to_string();

                     }
                 } else {
                     actual_number_files_syncing = total_number_files_syncing = 1;
                     status[2] = percent.to_string();
                 }
             } else if (args[0] == "Up") {
                 total_number_files_syncing = actual_number_files_syncing = 0;
                 percent =0;
             } 
            
            return true;

        } catch (SpawnError e) {
            status[1] = "Dropbox CLI not found!";
            status[0] = "Dropbox";
            if (prev_status_text != status[1] ) {
                prev_status_text = status[1];
                emit_status_change (status);
            }

            critical (e.message);
            return true;
        }

    }

    public bool is_installed {get; set;}

    public static string gen_share_link (string path) {
        string[] args = {"dropbox", "sharelink",path};
            string stdout;
            string stderr;
            int result;
            string url;

            Process.spawn_sync("/", args, null, SpawnFlags.SEARCH_PATH, null, out stdout, out stderr, out result);

            url = stdout;
            print(url);

            return url;
    }
    
}
