Drupal.behaviors.uccivicrmBehavior = function (context) {
  $('#edit-uc-civicrm-location-update').click(function() {
    if ($(this).attr('checked')) {
      $('#edit-uc-civicrm-location-type').attr('disabled', true);
    } else {
      $('#edit-uc-civicrm-location-type').removeAttr('disabled');
    }
  });
}
